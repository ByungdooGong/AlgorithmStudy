package acmic;

import java.util.Scanner;

class Node{
	int data;
	Node link;
}

public class Main_1158 {
	static void addNode(Node head, int data) {
		Node newNode = new Node();
		newNode.data = data;
		newNode.link = head.link;
		head.link = newNode;
	}
	static void deleteNode(Node head) {
		Node node = head.link;
		head.link = node.link;
		node = null;
	}
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		int K = s.nextInt();
		System.out.print("<");
		Node head = new Node();
		head.link = null;
		Node curr = head;
		for(int i=1; i<=N; i++) {
			addNode(curr, i);
			curr = curr.link;
		}
		curr.link = head.link;
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=K-1; j++) {
				head = head.link;
			}
			if(i==N) System.out.print(head.link.data+">");
			else System.out.print(head.link.data+", ");
			deleteNode(head);
		}
	}
}
