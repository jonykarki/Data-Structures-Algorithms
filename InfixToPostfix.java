import java.util.Scanner;

public class InfixToPostfix {
	
	/*
	  Convert infix expression to postfix expression by implementing a stack. 
	  Infix contains only single-digit operands, four binary operators 
	  (+, -, *, /) and parentheses.
	*/
	
	
	//precedence() method takes operator as input and return the precendence as an integer. 
	//Larger number indicates higher precedence. 
	public static int precedence (char ch) {
		if (ch == '+' || ch == '-') {
			return 1;
		} else if (ch == '*' || ch == '/') {
			return 2;
		}
		return 0;
	}
	
	public static void main(String[] args) {
		//Read user's input, no space between each character.
		Scanner sc = new Scanner(System.in);
		// get the infix expression from the user
		System.out.println("Please enter a infix expression: ");

		String infixExp = sc.next().replaceAll("\\s+","");
		String postFixExp = ""; //This is your postfix result.
		
		//Your implementation of infix to postfix algorithm goes here.
		StackReferenceBased stack = new StackReferenceBased();

		/**
		 * Convert the infix expression to postfix expression
		 * Precondition: String format is correct and only single digits 0-9 and
		 * 				*, /, +, - are used
		 * Postcondition: the correct equivalent postfix expression
		 */
		// go through the infixExp char by char
        for (int i = 0; i < infixExp.length(); i++) {
			// get the char at i
            char currentChar = infixExp.charAt(i);
			// if operand append to postFixExp
            if (Character.isDigit(currentChar)){
                postFixExp += currentChar;
            } else if (currentChar == '(') {
				// push is open brace
                stack.push(currentChar);
            } else if (currentChar == ')') {
                while (stack.peek().toString().charAt(0) != '(') {
					// pop and append till open braces
                    postFixExp += stack.pop().toString();
                }
				// remove the open braces 
                stack.pop();
            } else {
                while (!stack.isEmpty() && stack.peek().toString().charAt(0) != '(' && precedence(currentChar) <= 
				precedence(stack.peek().toString().charAt(0))) {
					// pop while not empty and satisfies everything above
					postFixExp += stack.pop().toString();
				}
				// push the curr char
				stack.push(currentChar);
            }
        }

		// pop everything remaining
		while (!stack.isEmpty()) {
			postFixExp += stack.pop().toString();
		}

		// print the postfix equivalent of the infix string
		System.out.println(String.format("The postfix equivalent is %s", postFixExp));

		/**
		 * BONUS: Calculate the value of expression from postfix
		 * Precondition: We have the correct postfix expression
		 * Postcondition: returns the value of the expression
		 */
		// empty and reuse the stack from before
		stack.popAll();

		// go through the postFixString
		for (int i = 0; i < postFixExp.length(); i++) {
			char currentChar = postFixExp.charAt(i);
			// add it to the stack if it is operand
			if (Character.isDigit(currentChar)) {
				stack.push(currentChar);
			} else {
				// get the top two operands
				int charFirst = Integer.parseInt(stack.pop().toString());
				int charSecond = Integer.parseInt(stack.pop().toString());
				// identify the operator and perform the operation
				switch (currentChar) {
					case '*':
						stack.push(charSecond * charFirst);
						break;
					case '/':
						stack.push(charSecond / charFirst);
						break;
					case '+':
						stack.push(charSecond + charFirst);
						break;
					case '-':
						stack.push(charSecond - charFirst);
						break;
					default:
						break;
				}
			}
		}

		// print the calculated value of the postfix expression
		System.out.println(String.format("The result of the postfix expression is %s", stack.pop().toString()));

		// close the scanner
		sc.close();
	}

}
