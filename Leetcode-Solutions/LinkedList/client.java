package LinkedList;

public class client {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		LRUCache lru=new LRUCache(1);
		lru.put(2,1);
	
		System.out.println(lru.get(2));
		lru.put(3,2);
		System.out.println(lru.get(2));
		
//		System.out.println(lru.get(3));
		
	}

}
