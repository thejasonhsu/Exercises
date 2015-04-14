import java.io.*;
import java.util.*;

public class DistinctWords 
{
	public static void main(String[] args) 
	{
		// Reader for input from the keyboard.
		Scanner input = new Scanner(System.in);
		
		// A tree set, ordering data according to string.
		TreeSet<String> wordSet = new TreeSet<String>();
		
		// Get the file name from the user.
		System.out.print("Enter a file to read from: ");
		String file = input.nextLine();
		input.close();
		
		try
		{
			// Try to open the file.
			Scanner fileReader = new Scanner(new File(file));
			
			// Read every word possible.
			while(fileReader.hasNext())
			{
				// Filter words by removing capitalized letters and special characters.
				String word = fileReader.next().toLowerCase().replaceAll("[.,;:]", "");
				wordSet.add(word);
			}

			// Iterate through all words in TreeSet.
			Iterator<String> iter = wordSet.iterator();
			
			// Print out the distinct words.
			System.out.println("Distinct Words: ");
			while(iter.hasNext())
				System.out.println("  " + iter.next());
			
			// Close the file.
			fileReader.close();
		}
		catch(FileNotFoundException f)
		{
			// If the file cannot be found, print an error.
			System.err.println("File Not Found!");
		}
	}
}
