// Write a program to find the node at which the intersection of two singly linked lists begins.


class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}


class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode endA = headA;
        while (endA.next != null) {
            endA = endA.next;
        }
        endA.next = headB;
        ListNode slow = headA, fast = headA, intersect = null;
        while (slow != null && fast != null && fast.next != null && intersect == null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                slow = headA;
                while (slow != fast) {
                    slow = slow.next;
                    fast = fast.next;
                }
                intersect = slow;
            }
        }

        endA.next = null;
        return intersect;
    }

    public static void main(String[] args) {
        ListNode a = new ListNode(2);
        ListNode b = new ListNode(3);
        a.next = new ListNode(5);
        ListNode intersect = new ListNode(8);
        a.next.next = intersect;
        b.next = intersect;
        intersect.next = new ListNode(33);
        Solution s = new Solution();
        System.out.println(s.getIntersectionNode(a, b) == intersect); 
    }
}