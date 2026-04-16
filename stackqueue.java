//stack
import java.util.*;
import javax.management.Query;
class Stack {
    private int[] arr;
    private int top;

    public Stack(int size) {
        arr = new int[size];
        top = -1;
    }

    public void push(int x) {
        if (top == arr.length - 1){ 
            System.out.println("Overflow");
        } else {
            arr[++top] = x;
        }
    }

    public int pop() {
        if (top == -1){
        System.out.println("Underflow");
        return -1;
        }
        return arr[top--];
    }

    public int peek() {
        if (top == -1) {
        System.out.println("Stack empty()");
        return -1;
        }
        return arr[top];
    }
}
//queue
class queue{
    private int [] arr;
     private int front, rear, size;

    public queue(int capacity) {
        arr = new int[capacity];
        front = size = 0;
        rear = capacity - 1;
    }
     public void enqueue(int x) {
        if (size == arr.length) {
            System.out.println("Queue is full");
            return;
        }
        rear = (rear + 1) % arr.length;
        arr[rear] = x;
        size++;
    }
     public int dequeue() {
        if (size == 0) {
            System.out.println("Queue is empty");
            return -1; 
        }
        int val = arr[front];
        front = (front + 1) % arr.length;
        size--;
        return val;
    }
     public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == arr.length;
    }

}
public class stackqueue{
    public static void main(String[] args) {
        System.out.println("----stack----");
        Stack stack = new Stack(5);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        System.out.println("Top element: " + stack.peek());
        System.out.println("Popped: " + stack.pop());
        System.out.println("Popped: " + stack.pop());
        
        System.out.println("----queue----");
        queue q = new queue(3);
        q.enqueue(100);
        q.enqueue(200);
        q.enqueue(300);
        System.out.println("Dequeued: " + q.dequeue());
        System.out.println("Dequeued: " + q.dequeue());
        System.out.println("Dequeued: " + q.dequeue());

    }
}