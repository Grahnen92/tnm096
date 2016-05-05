import java.awt.*; 
import javax.swing.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class main {
	public static void main(String [ ] args)
	{     	      
	      Sentence sTest = new Sentence();
	      sTest.addToSentence("(a|~a)&(c|d|e|f)&(g|h|i)");
	      sTest.print();
	      sTest.evaluate();
	      sTest.print();
	      System.out.println("success");
	}
}
