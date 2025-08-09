import java.util.*;

class Check{
	public static void main(String[] args) {
		Check cek = new Check();
		Scanner scan = new Scanner(System.in);
		System.out.print("Check your flag here: ");
		String Input = scan.nextLine();
		if(Input.length() < 10){
		    System.out.println("Flag can't be that short");
		    System.out.println("Don't FORGOR To Use agrihack Flag Format!!!");
		}else if(Input.substring(0,9).equals("agrihack{") && Input.substring(Input.length()-1, Input.length()).equals("}")){
			String subInput = Input.substring(9,Input.length()-1);
			if(cek.shuffle(subInput).equals("__ttu537ahR1fhl_us9_fjlett1")){
				System.out.println("Congratulation, your flag is RILLL!!");
			}else if(cek.shuffle(subInput).equals("3h1hutf_5_la9t1j_ltus_7ftRe")){
			    System.out.println("Hey, that's illegal!!");
			}else{
				System.out.println("That's a fake flag");
			}
		}else{
			System.out.println("Use agrihack Flag Format!!!");
		}
	}
	
	public String shuffle(String flag){
		char[] temp = new char[27];
		int j = flag.length()-1;
        if(j+1 != 27){
            return "";
        }
        for (int i = 0; i <= j; i+=3){
            temp[i] = flag.charAt((i+6)%27);
        }
        for (int i = j; i > 0; i-=3){
            temp[i] = flag.charAt((i+24)%27);
        }
        for (int i = 1; i <= j; i+=3){
            temp[i] = flag.charAt((i+12)%27);
        }
        String s = new String(temp);
		return s;
	}
}