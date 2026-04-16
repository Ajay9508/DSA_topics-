import java.util.*;
import java.util.Stack;
public class validparenthesis {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string with parentheses: ");
        String str = sc.nextLine();
        Stack<Character> stack = new Stack<Character>();
        boolean balanced = true;

        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);

            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (stack.isEmpty()) {
                    balanced = false;
                    break;
                }

                char top = stack.pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    balanced = false;
                    break;
                }
            }
        }

        if (!stack.isEmpty()) {
            balanced = false;
        }

        if (balanced) {
            System.out.println("Balanced");
        } else {
            System.out.println("Not Balanced");
        }

        sc.close();
    }
}