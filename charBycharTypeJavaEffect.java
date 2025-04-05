public class charBycharTypeJavaEffect {
    public static void main(String[] args) {
        final String name = "Parthik Kumar Das";
        StringBuilder s = new StringBuilder("");

        // Iterate over each character in the input name
        for (int i = 0; i < name.length(); i++) {
            char currentChar = name.charAt(i);

            if (!Character.isAlphabetic(currentChar)) {
                s.append(currentChar);  // Append non-alphabetic characters directly
            } else {
                boolean found = false;

                // Type through uppercase letters (A-Z)
                for (char ch = 'A'; !found && ch <= 'Z'; ch++) {
                    s.append(ch);  // Append character to StringBuilder
                    System.out.print("\r" + s.toString());  // Print the current string with carriage return (to overwrite line)
                    if (ch == currentChar) {  // Check if current char matches
                        found = true;
                        break;
                    }
                    s.deleteCharAt(s.length() - 1);  // Remove last inserted character
                    try {
                        Thread.sleep(100);  // Delay for a "typing" effect (100 ms)
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }

                // Type through lowercase letters (a-z)
                for (char ch = 'a'; !found && ch <= 'z'; ch++) {
                    s.append(ch);  // Append character to StringBuilder
                    System.out.print("\r" + s.toString()); // Print the current string
                    if (ch == currentChar) {  // Check if current char matches
                        found = true;
                        break;
                    }
                    s.deleteCharAt(s.length() - 1);  // Remove last inserted character
                    try {
                        Thread.sleep(100);  // Delay for a "typing" effect (100 ms)
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }
}
