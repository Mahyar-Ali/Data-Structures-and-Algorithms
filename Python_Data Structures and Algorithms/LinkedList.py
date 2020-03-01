class Element:
    def __init__(self,value):
        self.value = value
        self.next = None
class LinkedList :
    def __init__(self,head = None):
        self.head = head
    def append (self,new_element):
        current = self.head
        if self.head:
            while current.next:
                current= current.next
            current.next = new_element
        else:
            self.head= new_element
    def get_position (self,position):
        current = self.head
        if (position<1):
            return  None
        for i in range (1,position+1):
            if i == position :
                return  current
            current = current.next
        return None
    def insert(self,new_element,position):
        current = self.head
        if position>1:
            for i in range (1,position):
                if i == position-1:
                    new_element.next = current.next
                    current.next = new_element
                current = current.next
        elif position == 1:
            new_element.next = self.head
            self.head = new_element
    def delete (self,value):
        current = self.head
        prev = None
        while current.value != value  :
                    prev = current
                    current = current.next
        if prev :
            prev.next = current.next
        else :
            self.head = current.next

# Test cases
# Set up some Elements
e1 = Element(1)
e2 = Element(2)
e3 = Element(3)
e4 = Element(4)

# Start setting up a LinkedList
ll = LinkedList(e1)
ll.append(e2)
ll.append(e3)
ll.insert(e4,3)
# Should print 4 now

ll.delete(3)
# Should print 2 now
print (ll.get_position(1).value)
# Should print 4 now
print (ll.get_position(2).value)
# Should print 3 now
print (ll.get_position(3).value)
#print (ll.get_position(4).value)
