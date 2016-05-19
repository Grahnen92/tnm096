import java.awt.*; 
import javax.swing.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class main {
	public static void main(String [ ] args)
	{     	      
	      Sentence sTest = new Sentence();
	      //sTest.addToSentence("a|~a");
		  //sTest.addToSentence("d|e|f|~c");
		  //sTest.addToSentence("b|a|c");
		  //sTest.addToSentence("d|~c");
	      sTest.addToSentence("s|n");
	      sTest.addToSentence("~s");
	      sTest.addToSentence("p|n");
	      sTest.addToSentence("~n|p");
	      //sTest.addToSentence("s");
	      
		  /*sTest.addToSentence("~g|h|g|i|~g");
		  sTest.addToSentence("~j|~j");
	      sTest.addToSentence("~m");
		  sTest.addToSentence("~k|~k");
	      sTest.addToSentence("h|i");
		  sTest.addToSentence("h");
		  sTest.addToSentence("~c|~h");*/
		  sTest.print();
	      sTest.evaluate();
	      sTest.print();
	      System.out.println("success!");
	}
}
