import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;


public class LoveCalculator {

	static int staticshifts;
	public static void main(String[] args)
	{
		
		System.out.println("WELCOME TO THE LOVE CALCULATOR APPLICATION");
		
		String flames="FLAMES";
		char RootWord[]=flames.toCharArray();
		int uniqCharacters=GetNames();
		staticshifts=uniqCharacters;
		
		System.out.print("Your Relationship will end ");
		
		FindRelationship(RootWord,uniqCharacters);
			
		System.out.println("\nTHANK YOU");
	}

	
	private static int GetNames() 
	{
		
		Scanner s=new Scanner(System.in);
		System.out.println("Enter your name: ");
		String Fname=s.next();
		System.out.println("Enter your crush name: ");
		String Sname=s.next();
		
		Set<Character> set1=new TreeSet<Character>();
		for(int i=0;i<Fname.length();i++)
			set1.add(Fname.charAt(i));
		
		Set<Character> set2=new TreeSet<Character>();
		for(int i=0;i<Sname.length();i++)
			set2.add(Sname.charAt(i));
		
		set1.retainAll(set2);
		s.close();
		return Fname.length()+Sname.length()-(2*set1.size());
	}

	private static void FindRelationship(char[] rootWord, int uniqCharacters)
	{
		char initial=rootWord[0];
		if(uniqCharacters>1)
		{
			for(int i=1;i<rootWord.length;i++)
				rootWord[i-1]=rootWord[i];
			rootWord[rootWord.length-1]=initial;
		FindRelationship(rootWord,uniqCharacters-1);
		}
		else if(rootWord.length==1)		PrintRelationship(rootWord[0]);
		else
		{
			String word=String.valueOf(rootWord);
			String newword=word.substring(1);
			rootWord=newword.toCharArray();
		FindRelationship(rootWord,staticshifts);
		}
	}
	
private static void PrintRelationship(char relationship) {
		
	switch(relationship)
	{
	case 'F':System.out.print("in Friendship");break;
	case 'L':System.out.print("in Love");break;
	case 'A':System.out.print("in Affection");break;
	case 'M':System.out.print("in Marriage");break;
	case 'E':System.out.print("in Enmity");break;
	case 'S':System.out.print("as Brother and Sister");break;
	default :
		System.out.println("Error");
	
	}


}
}
