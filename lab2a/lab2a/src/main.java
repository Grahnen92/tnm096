import java.awt.*; 
import javax.swing.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class main {
	public static void main(String [ ] args)
	{
	      int test = 1;
	      for (int i = 0; i < 10 ; i++){
	    	  System.out.println(i);
	      }
	      
	      Clause cTest = new Clause('A', true, true);
	      Sentence sTest = new Sentence();
	      
	      sTest.addClause(cTest);
	      
	      System.out.println("success");
	}
}
