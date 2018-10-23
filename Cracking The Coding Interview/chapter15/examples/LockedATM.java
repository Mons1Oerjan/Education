public class LockedATM {
    private Lock lock;
    private int balance = 100;

    public LockedATM() {
        lock = new ReentrantLock();
    }

    public int withdraw(final int value) {
        lock.lock();
        int temp = balance;
        try {
            Thread.sleep(100);
            temp -= value;
            Tread.sleep(100);
            balance = temp;
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        lock.unlock();
        return temp;
    }

    public int deposit(final int value) {
        lock.lock();
        int temp = balance;
        try {
            Thread.sleep(100);
            temp += value;
            Tread.sleep(300);
            balance = temp;
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        lock.unlock();
        return temp;
    }
}
