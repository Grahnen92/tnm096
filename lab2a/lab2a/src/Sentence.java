import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
// & | > = ~


public class Sentence {
	ArrayList<String> s;
	
	public Sentence(){
		s = new ArrayList<String>();
	}
	
	public void addToSentence(String c){
		s.add(c);
	}
	
	// Change from boolean to clause
	public void evaluate() {
		//char test = s.charAt(0);
		ArrayList<String> newS = new ArrayList<String>();
		String converted;
		
		for(int i = 0; i < s.size(); i++){

			converted = clean(s.get(i));
			
			//check if the new clause is empty && check if the new clause is already in the sentence
			if(!converted.isEmpty() && !contains(converted, newS)){
				
				newS.add(converted);	
			}
		}
		
		s = newS;
		
		
		print();
		System.out.println("clean");
		
		// Evaluate resolution
		for(int i = 0; i < s.size(); i++){
			for(int j = 0; j < s.size(); j++){
				
				if(i == j)
					continue;
				
				System.out.println("indicies: " + i + " " + j);
				
				resolve(s.get(i), s.get(j));
			}
		}
		
		System.out.println("finding subsets\n");
		
		int sSize;
		String tmpString;
		for(int i = 0; i < s.size(); i++)
		{
			System.out.print( i + "\nbf: ");
			print();
			sSize = s.size();
			tmpString = s.get(i); 
			subsetRm(tmpString);
			s.add(tmpString);
			if(sSize - s.size() != 0 )
				i = 0; 
			
			System.out.print("af: ");
			print();
			System.out.println("");
		}
		
	}
	
	public void resolve(String m, String n) {
		int c1 = 0, ml = m.length();
		Boolean not;
		System.out.print("resolving: ");
		print();
		
		//walk through the entire m sentence
		while(c1 < m.length()) {
			//find the next non operand
			while(c1 < m.length() && (m.charAt(c1) == '|' || m.charAt(c1) == '~') ){
				c1++;
			}
			String ch = "" + m.charAt(c1);
			if(c1 != 0 && m.charAt(c1-1) == '~'){
				if(n.contains(ch + "")){
					n = n.replace(ch + "|", "");
					if(c1 < m.length()) n = n.replace("|" + ch, "");
					if(c1 < m.length()) n = n.replace(ch + "", "");
					if(c1 < m.length()) m = m.replace("~" + ch + "|", "");
					if(c1 < m.length()) m = m.replace("|~" + ch, "");
					if(c1 < m.length()) m = m.replace("~" + ch, "");
				} else c1++;
				
			}
			else{
				if(n.contains("~" + ch)){
					n = n.replace("~" + ch + "|", ""); 
					if(c1 < m.length()) n = n.replace("|~" + ch, "");
					if(c1 < m.length()) n = n.replace("~" + ch, "");
					if(c1 < m.length()) m = m.replace( ch + "|", "");
					if(c1 < m.length()) m = m.replace("|" + ch, "");
					if(c1 < m.length()) m = m.replace(ch + "", "");
				}
				c1++;
			}
		}
			
		System.out.println("m,n " + m + " " + n);

		//clean strings 
		if(ml != m.length()){
			if(!n.isEmpty() && !m.isEmpty()){
				if(subset(n,m) )
					s.add(n);
				else if(subset(m,n))
					s.add(m);
				else
					s.add(n + "|" + m);
			}
			else if (!n.isEmpty()){
				//subsetRm(n);
				s.add(n);
			}
			else if(!m.isEmpty()){
				//subsetRm(m);
				s.add(m);
			}	
		}
	}
	
	public String clean(String _input) {
	
		System.out.println("input: " + _input);
		int c1 = 0;
		Boolean not;
		String newS = ""; 
		
		//walk through the entire sentence
		while(c1 < _input.length()){
			
			//find the next non operand
			while(c1 < _input.length() && (_input.charAt(c1) == '|' || _input.charAt(c1) == '~') ){
				c1++;
			}
			if(c1 != 0 && _input.charAt(c1-1) == '~')
				not = true;
			else
				not = false;
			
			//walk through the sentence and look for duplicates
			for(int i = c1 + 1; i < _input.length(); i++){
			      
				if(_input.charAt(c1) == _input.charAt(i)){
					//A | ~A, remove all A
					if(_input.charAt(i - 1) == '~' && !not){
						_input = _input.substring(0, i - 2 ) + _input.substring(i+1, _input.length() );
						i = i - 2;
						for(int j = i; j < _input.length(); j++){
							if(_input.charAt(j) == _input.charAt(c1)){
								if(_input.charAt(c1 - 1) == '~' ){
									_input = _input.substring(0, j - 2 ) + _input.substring(j+1, _input.length() );
									j = j - 2;
								}
								else{
									_input = _input.substring(0, j - 1 ) + _input.substring(i+1, _input.length() );
									j = j - 1;
								}
							}
						}
						// Remove the first instance of the character
						if(c1 != 0)
							_input = _input.substring(0, c1 - 1 ) + _input.substring(c1 + 1, _input.length() );
						else if(c1 < _input.length())
							_input = _input.substring(c1 + 1, _input.length() );
						break;
					}
					//A | A, remove duplicate
					else if(_input.charAt(i - 1) != '~' && !not){
						_input = _input.substring(0, i - 1 ) + _input.substring(i+1, _input.length() );
						i = i - 1;
					}
					//~A | ~A, remove duplicate
					else if(_input.charAt(i - 1) == '~' && not){
						_input = _input.substring(0, i - 2 ) + _input.substring(i+1, _input.length() );
						i = i - 2;
					}
					//~A | A, remove all A
					else if(_input.charAt(i - 1) != '~' && not){
						_input = _input.substring(0, i - 1 ) + _input.substring(i+1, _input.length() );
						i = i - 1;
						
						for(int j = i; j < _input.length(); j++){
							if(_input.charAt(j) == _input.charAt(c1)){
								if(_input.charAt(c1 - 1) == '~' ){
									_input = _input.substring(0, j - 2 ) + _input.substring(j+1, _input.length() );
									j = j - 2;
								}
								else{
									_input = _input.substring(0, j - 1 ) + _input.substring(i+1, _input.length() );
									j = j - 1;
								}
							}
						}
						
						// Remove the first instance of the character
						if(c1 != 0) {
							_input = _input.substring(0, c1 - 1 ) + _input.substring(c1+2, _input.length() );
						}
						else if(c1 < _input.length())
							_input = _input.substring(c1+1, _input.length() );
						break;
					}	
				}			
			}
			c1++;
		}
		
		System.out.println("output: " + _input + "\n");

		return _input;
	}
	
	public Boolean contains(String c, ArrayList<String> _al){
		
		for (int i = 0; i < _al.size(); i++){
			if(_al.get(i).equals(c) )
				return true;
		}
		
		return false;
	}
	
	public void subsetRm(String c){
		Boolean isSubset = true;
		// Loop through clauses
		for(int i = 0; i < s.size(); i++){
			// Loop through letters in clause c
			for(int j = 0; j < c.length(); j++){
				if(String.valueOf(c.charAt(j)).equals("|") || String.valueOf(c.charAt(j)).equals("~") )
					continue;
				
				if(j != 0 && c.charAt(j - 1) == '~'){
					if( !s.get(i).contains(String.valueOf(c.charAt(j - 1)) + String.valueOf(c.charAt(j))) )
						isSubset = false;
				}
				else if( !s.get(i).contains(String.valueOf(c.charAt(j))) ){
					isSubset = false;
				}
				
			}
			if(isSubset){
				s.remove(i);
				if(s.size() > 0)
					i--;
			}
				
			
			isSubset = true;
		}
	}
	
	public Boolean subset(String c, String s){
		// Loop through letters in clause c
		for(int j = 0; j < c.length(); j++){
			if(String.valueOf(c.charAt(j)).equals("|") || String.valueOf(c.charAt(j)).equals("~") )
				continue;
			
			if(j != 0 && c.charAt(j - 1) == '~'){
				if( !s.contains(String.valueOf(c.charAt(j - 1)) + String.valueOf(c.charAt(j))) )
					return false;
			}
			else if( !s.contains(String.valueOf(c.charAt(j))) ){
				return false;
			}
			
		}
		return true;
	}
	
	public void print() {	
		for(int i = 0; i < s.size() - 1; i++){
			System.out.print("(" + s.get(i) + ")&") ;
		}
		
		 System.out.println("("+s.get(s.size() - 1) + ")");
	}
}
