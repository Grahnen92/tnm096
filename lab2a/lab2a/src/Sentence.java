import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
// & | > = ~


public class Sentence {
	String s;
	
	public Sentence(){
		s = "";
	}
	
	public void addToSentence(String c){
		s += c;
	}
	
	// Change from boolean to clause
	public void evaluate() {
		//char test = s.charAt(0);
		String newS = "";
		String converted;
		int start, end;
		
		start = 0;
		
		//for(int i = 0; i < s.length(); i++){
		//	while(true){
		do{
			end = start +1;
			while(s.charAt(end) != ')'){
				end++;
			}
			
			converted = resolve(s.substring(start + 1, end));
			if(converted != "")
				newS += "(" + converted + ")";
			
			if(end != s.length() - 1)
				newS += s.charAt(end+1);
			else
				break;
			
			
			start = end + 2;
		} while(end != s.length() - 1);
		
		s = newS;
	}
	
	public String resolve(String _input) {
	
		System.out.println(_input);
		int c1 = 0;
		Boolean not;
		String newS = ""; 
		
		//walk through the entire sentence
		while(c1 < _input.length()){
			
			System.out.println("c1: " + c1);
			//find the next non operand
			while(_input.charAt(c1) == '|' && c1 == '~' && c1 < _input.length()){
				c1++;
			}
			if(c1 != 0 && _input.charAt(c1-1) == '~')
				not = true;
			else
				not = false;
			
			//walk through the sentence and look for duplicates
			for(int i = c1 + 1; i < _input.length(); i++){
			      System.out.println(i);

				if(_input.charAt(c1) == _input.charAt(i)){
					//A | ~A, remove all A
					if(_input.charAt(i - 1) == '~' && !not){
						_input = _input.substring(0, i - 2 ) + _input.substring(i+1, _input.length() );
						i = i - 2;
						System.out.println(i + " " + _input.length());
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
						System.out.println("debug");
						if(c1 != 0)
							_input = _input.substring(0, i - 1 ) + _input.substring(i+1, _input.length() );
						else if(i < _input.length())
							_input = _input.substring(i+1, _input.length() );
						
						System.out.println("debug");
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
						
						if(c1 != 0)
							_input = _input.substring(0, i - 2 ) + _input.substring(i+1, _input.length() );
						else if(c1 < _input.length())
							_input = _input.substring(i+1, _input.length() );
						
						break;
					}	
				}			
			}
			c1++;
		}
		
		return _input;
	}
	
	public void print() {
		 System.out.println(s);
	}
}
