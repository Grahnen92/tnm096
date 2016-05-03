import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Sentence {

	List<Clause> clauses;
	List<Character> operands;

	public Sentence(){
		clauses = new ArrayList<Clause>();
		operands = new ArrayList<Character>();
	}
	
	public void addClause(Clause _clause){
		clauses.add(_clause);
	}

	public void addOperand(Character _operand){
		operands.add(_operand);
	}
	
	// Change from boolean to clause
	public boolean evaluate() {
	Clause c1 = clauses.remove(1), c2 = clauses.remove(1);
	char op = operands.remove(1);
	
	
		// AND/SNITT
		if(op == 'A'){
			if(c1.state && c2.state)
				return true;
			else
				return false;
		}
		//OR/UNION
		if(op == 'O'){
			if(c1.state || c2.state)
				return true;
			else
				return false;
		}
		//NOT
		if(op == 'N'){
			return false;
		}
		//IMPLIES
		if(op == 'I'){
			if(c1.state && !c2.state)
				return false;
			else
				return true;
		}
		//IFANDONLYIF
		if(op == 'F'){
			if(!c1.state && !c2.state)
				return true;
			else if(c1.state && c2.state)
				return true;
			else
				return false;
		}
		return false;
	}
}
