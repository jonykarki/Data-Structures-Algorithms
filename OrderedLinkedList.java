class OrderedLinkedList {
    static class IntegerNode {
        public int item;
        public IntegerNode next;

        public IntegerNode(int newItem) {
            item = newItem;
            next = null;
        } // end constructor

        public IntegerNode(int newItem, IntegerNode nextNode) {
            item = newItem;
            next = nextNode;
        } // end constructor
    } // end class IntegerNode

    // keep the head node
    static IntegerNode head = null;

    public static void main(String[] args) {
        // Test the linked list
        add(3);
        add(6);
        add(4);
        add(2);
        traverse();
        add(5);
        traverse();
        delete(3);
        traverse();
        delete(2);
        traverse();
    }

    private static void delete(int i) {
        System.out.println("Deleting " + i);
        IntegerNode prev = null;
        IntegerNode curr = head;
        // go until the value is found
        while (curr != null && i != curr.item) {
            prev = curr;
            curr = curr.next;
        }
        // if curr is null we're either empty or at the end
        if (curr == null)
            System.out.println(i + " not in the linked list!");
        else
        // if prev is null it's the beginning
        if (prev == null)
            // move head forward
            head = head.next;
        else
            // we're inside the linked list somewhere so just change the prev's next
            prev.next = curr.next;
    }

    private static void traverse() {
        // traverse the list
        for (IntegerNode curr = head; curr != null; curr = curr.next) {
            // print the item and the arrow (conditionally)
            System.out.print(curr.item + (curr.next != null ? " -> " : ""));
        }
        System.out.println();
    }

    public static void add(int newInt) {
        System.out.println("Adding " + newInt);
        IntegerNode prev = null;
        IntegerNode curr = head;
        // find the place to put the integer in the list
        while (curr != null && newInt > curr.item) {
            prev = curr;
            curr = curr.next;
        }
        // the new Node to be added
        IntegerNode newNode = new IntegerNode(newInt);
        // prev is null then beginning.
        if (prev == null) {
            // insert at the beginning
            if (head != null)
                newNode.next = head;
            // change the head reference to the beginning
            head = newNode;
        } else {
            // the normal case for addition inside the linked list
            // change the newnode to refer to curr and prev to refer to newnode
            newNode.next = curr;
            prev.next = newNode;
        }
    }
}