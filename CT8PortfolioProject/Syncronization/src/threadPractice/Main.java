package threadPractice;

public class Main {
	
	public static void countUp() {
		for (int i = 0; i <= 20; i++) {
			System.out.println(i);
		}
		System.out.println("Completed count up.");
	}
	
	public static void countDown() {
		for (int i = 20; i >= 0; i--) {
			System.out.println(i);
		}
		System.out.println("Completed count down.");
	}

	public static void main(String[] args) {
		
		Thread thread1 = new Thread(Main::countUp);
		Thread thread2 = new Thread(Main::countDown);
		
		thread1.start();
		try {
			thread1.join();
		} catch (InterruptedException e) {
			
			e.printStackTrace();
		}
		
		thread2.start();
		try {
			thread2.join();
		} catch (InterruptedException e) {
			
			e.printStackTrace();
		}

	}

}
