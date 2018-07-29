package assembly;
import java.io.*;
import java.text.NumberFormat;
import java.text.ParsePosition;
import java.util.Map;
import java.util.TreeMap;


public class AsmToHackAssembler 
{
	private static Map<String, String> symbols;
	private static Map<String, String> jump;
	private static Map<String, String> comp;
	private static Map<String, String> dest;
	
	public static enum commandType{A_COMMAND, L_COMMAND, C_COMMAND}
	public static commandType command;
	
	private static String[] lineArray;
	private static int counter = 0;
	private static int linecounter = 0;
	private static int nextSymbol = 16; //next entry in the symbols tree
	private static String inputFileName = "prog.asm", outputFileName = "prog.hack";
	private static String dst, cmp, jmp;
	
	
	public static void main(String[] args) 
	{
		initializeMaps(); //fill in hashtree values
		File outputFile = new File(outputFileName); 
		String line = "";
		
		//set up the input stream:
		FileInputStream stream = null;
		try {
			stream = new FileInputStream(inputFileName);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		int content;
		try {
			while ((content = stream.read()) != -1) 
			{
			    line += (char) content; // convert to char
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		DataInputStream datain = new DataInputStream(stream);
		BufferedReader br = new BufferedReader(new InputStreamReader(datain));
		
		line = removeComments(line); //remove all comments from the inputfile
		
		lineArray = line.split("\n"); //copy every line into a String array
		
		//remove all whitespace:
		for (int i = 0; i < lineArray.length; i++)
		{
			lineArray[i] = lineArray[i].trim();
		}
		
		//set up the filewriter:
		FileWriter writer = null;
		try {
			writer = new FileWriter(outputFile);
		} catch (IOException e) {
			e.printStackTrace();
		}
		BufferedWriter bw = new BufferedWriter(writer);
		
		
		//fill in missing symbols in the mapTree:
		counter = 0; //array index
		while(counter != lineArray.length)
		{
			commandType(); //find the command type and set the command
			if (command == commandType.L_COMMAND) //L_command
			{
				symbols.put(grabSymbol(), Integer.toString(linecounter));
			}
			else //go to next line
			{
				linecounter++; 
			}
			counter++; 
		}
		
		//convert to binary, append 0's (in front) and write to prog.hack:
		counter = 0; //reset the array index
		while (counter != lineArray.length)
		{
			commandType(); //find the command type and set command
			if (command == commandType.A_COMMAND)
			{
				if (lineArray[counter].startsWith("@"))
				{
					//A_command that starts with @:
					String symbol = grabSymbol();
					
					if (isNumber(symbol)) //check if symbol is a number
					{
						int xxx = Integer.parseInt(symbol);
						symbol = convert_dec_to_bin(xxx); //symbol is now binary
						symbol = addZero(symbol); //put 0's in front
						try {
							bw.write(symbol + '\n'); //write symbol to .hack
						} catch (IOException e) {
							e.printStackTrace();
						}
					}
					else //if symbol is not a number
					{ 
						if (!symbols.containsKey(symbol))
						{
							//add the unknown symbol to the symbols tree:
							symbols.put(symbol, Integer.toString(nextSymbol));
							nextSymbol++;
						}
						if (symbols.containsKey(symbol))
						{
							//already exists in the symbols tree:
							String symbol2 = symbols.get(symbol);
							int xxx = Integer.parseInt(symbol2);
							symbol2 = convert_dec_to_bin(xxx);
							symbol2 = addZero(symbol2); //add (16-symbol2.length) 0's to the front
							try {
								bw.write(symbol2 + '\n');  //write symbol2 to .hack
							} catch (IOException e) {
								e.printStackTrace();
							}
						}
					}
				}
			} //end of A_COMMAND
			
			if (command == commandType.C_COMMAND)
			{
				if (lineArray[counter].contains("="))
				{   
					dst = dest.get(dest());
					cmp = comp.get(comp());
					jmp = jump.get("NULL"); //no jump required
					try {
						bw.write("111" + cmp + dst + jmp +'\n');
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
				else if (lineArray[counter].contains(";"))
				{
					dst = dest.get("NULL"); //no dest required
					cmp = comp.get(comp());
					jmp = jump.get(jump()); 
					try {
						bw.write("111" + cmp + dst + jmp +'\n');
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
			}
			counter++; //next array index
		}//end of while loop
		
		try {
			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	
	
	/**
	 * method that removes all comments from the input file
	 */
	public static String removeComments(String fileName) 
	{
		String newFile =  fileName.replaceAll( "//.*|(\"(?:\\\\[^\"]|\\\\\"|.)*?\")|(?s)/\\*.*?\\*/|(?m)^[ \t]*\r?\n|null|\t", "" );
		newFile = newFile.replaceAll("(?m)^[ \t]*\r?\n", "");
        return newFile;
	}
	
	/**
	 * decimal to binary converter
	 * @param decimal The decimal number that will be converted to binary
	 * @return Returns the binary number
	 */
	public static String convert_dec_to_bin(int decimal) 
	{
		String binary = Integer.toBinaryString(decimal);
		return binary;
	}
	
	
	/**
	 * Method that grabs the symbol following a @ or a (
	 * @return whatever follows @ or (
	 */
	public static String grabSymbol()
	{
		String symbol = "";
		if(lineArray[counter].startsWith("@"))
		{
			symbol = lineArray[counter];
			symbol = symbol.replaceAll("@", "");
		}
		else if(lineArray[counter].startsWith("("))
		{
			symbol = lineArray[counter];
			symbol = symbol.replaceAll("\\((.*?)\\)", "$1");
		}
		return symbol;
	}
	
	//
	/**
	 * method that returns ((16-given string length) number of 0's + the given string)
	 * @param num The number you want to add 0's in front of
	 * @return Returns the input number with 0's in front (length = 16)
	 */
	public static String addZero(String num)
	{
		StringBuilder sb = new StringBuilder();
		//fill in 0's:
		for (int i = 16 - num.length(); i > 0; i--) 
		{
		    sb.append('0');
		}
		//then fill in the given string:
		sb.append(num);
		String result = sb.toString();
		return result;
	}
	

	/**
	 * method to set the command type (L, A or C)
	 */
	public static void commandType()
	{
		if(lineArray[counter].startsWith("("))
		{
			command = commandType.L_COMMAND;
		}
		else if(lineArray[counter].startsWith("@"))
		{
			command = commandType.A_COMMAND;
		}
		else
		{
			command = commandType.C_COMMAND;
		}
	}
	
	// checks if the given String is a number for any locale
	/**
	 * Method that checks if the given String is a number for any locale
	 * @param isnumber The number you want to check
	 * @return Boolean: True if the number is a number
	 */
	public static boolean isNumber(String isnumber)
	{
		NumberFormat formatter = NumberFormat.getInstance();
		ParsePosition position = new ParsePosition(0);
		formatter.parse(isnumber, position);	
		return isnumber.length() == position.getIndex();	
	}
	
	//get dest
	public static String dest() 
	{
		if(lineArray[counter].contains("="))
		{
			String destination = lineArray[counter];
			
			int endIndex = destination.lastIndexOf("=");
			destination =  destination.substring(0,endIndex);
			return destination;
		}
		return null;
	}
	
	//get comp
	public static String comp() 
	{
		String compare = lineArray[counter]; 
		if(lineArray[counter].contains("="))
		{
			int endIndex = compare.lastIndexOf("=");
			compare = compare.substring(endIndex + 1,compare.length());
		}
		else if(lineArray[counter].contains(";"))
		{
			int endIndex = compare.lastIndexOf(";");
			compare =  compare.substring(0,endIndex);
		}
		return compare;
	}
	
	//get jump
	public static String jump() 
	{
		if(lineArray[counter].contains(";"))
		{
			String jump = lineArray[counter]; 
			int endIndex = jump.lastIndexOf(";");
			return jump.substring(endIndex+1,jump.length());
		}
		return null;
	}
	
	
	
	public static void initializeMaps()
	{
		symbols = new TreeMap<String, String>();
		symbols.put("SP", "0");
		symbols.put("LCL", "1");
		symbols.put("ARG", "2");
		symbols.put("THIS", "3");
		symbols.put("THAT", "4");
		symbols.put("R0", "0");
		symbols.put("R1", "1");
		symbols.put("R2", "2");
		symbols.put("R3", "3");
		symbols.put("R4", "4");
		symbols.put("R5", "5");
		symbols.put("R6", "6");
		symbols.put("R7", "7");
		symbols.put("R8", "8");
		symbols.put("R9", "9");
		symbols.put("R10", "10");
		symbols.put("R11", "11");
		symbols.put("R12", "12");
		symbols.put("R13", "13");
		symbols.put("R14", "14");
		symbols.put("R15", "15");
		symbols.put("SCREEN", "16384");
		symbols.put("KBD", "24576");
		
		jump = new TreeMap<String, String>();
		jump.put("NULL", "000");
		jump.put("JGT", "001");
		jump.put("JEQ", "010");
		jump.put("JGE", "011");
		jump.put("JLT","100");
		jump.put("JNE","101");
		jump.put("JLE","110");
		jump.put("JMP", "111");
		
		comp = new TreeMap<String, String>();
		comp.put("0", "0101010");
		comp.put("1", "0111111");
		comp.put("-1","0111010");
		comp.put("D", "0001100");
		comp.put("A", "0110000");
		comp.put("!D", "0001101");
		comp.put("!A", "0110001");
		comp.put("-D", "0001111");
		comp.put("-A", "0110011");
		comp.put("D+1","0011111");
		comp.put("A+1","0110111");
		comp.put("D+A","0000010");
		comp.put("D-A","0010011");
		comp.put("A-D","0000111");
		comp.put("D&A","0000000");
		comp.put("D|A","0010101");	
		comp.put("M","1110000");
		comp.put("!M","1110001");
		comp.put("-M","1110011");
		comp.put("M+1","1110111");
		comp.put("M-1","1110010");
		comp.put("D+M","1000010");
		comp.put("D-M","1010011");
		comp.put("M-D","1000111");
		comp.put("D&M","1000000");
		comp.put("D|M","1010101");
		comp.put("D-1","0001110");
		comp.put("A-1","0110010");
		
		dest = new TreeMap<String, String>();
		dest.put("NULL","000");
		dest.put("M","001");
		dest.put("D","010");
		dest.put("MD","011");
		dest.put("A","100");
		dest.put("AM","101");
		dest.put("AD","110");
		dest.put("AMD","111");
	}

}
