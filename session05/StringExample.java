public class StringExample {
	public static void main(String[] args) {
		String s = "";
		for (int i = 0; i < 1000000; i++)
			s += i;                           //s = "" + 0 --> "0"
		//  s = "0" + 1 ==> "01" --> "012" --> "0123"

		StringBuilder b = new StringBuilder();
		for (int i = 0; i < 1000000; i++)
			b.append(i);

		StringBuilder b = new StringBuilder(6000000);
		for (int i = 0; i < 1000000; i++)
			b.append(i);
		

		
	}
}
