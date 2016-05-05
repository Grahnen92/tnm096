


public class Clause {
	char something;
	//string something;

	boolean state;
	boolean not;

	public Clause(){
		state = false;
		not = false;
	}

	public Clause(char _something, boolean _state, boolean _not){
		something = _something;
		state = _state;
		not = _not;
	}


}
