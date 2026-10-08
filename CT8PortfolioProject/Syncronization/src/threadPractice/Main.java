package threadPractice;

public class Main {
	//method to iterate up through numbers 0 - 20 and print them in the console.
	public static void countUp() {
		for (int i = 0; i <= 20; i++) {
			System.out.println(i);
		}
		//communicate when the program is done counting up.
		System.out.println("Completed count up.");
		System.out.println();
	}
	
	//method to iterate down through numbers 20 - 0 and print them in the console.
	public static void countDown() {
		for (int i = 20; i >= 0; i--) {
			System.out.println(i);
		}
		//communicates when the program is done counting down.
		System.out.println("Completed count down.");
	}

	public static void main(String[] args) {
		//Create new threads calling for the countUp and countDown methods within the Main class.
		Thread thread1 = new Thread(Main::countUp);
		Thread thread2 = new Thread(Main::countDown);
		
		//Initiate thread 1.
		thread1.start();
		
		//try catch block for the join to catch and report the InterruptedException and print out a stackTrace if the exception is caught.
		try {
			thread1.join();
		} catch (InterruptedException e) {
			
			e.printStackTrace();
		}
		
		//After thread1 is joined initiate thread2.
		thread2.start();
		
		//Try catch block to join thread2 back to the main thread. 
		//Used to catch and report the InterruptedException and print out a stackTrace if the exception is caught.
		try {
			thread2.join();
		} catch (InterruptedException e) {
			
			e.printStackTrace();
		}

	}

}
