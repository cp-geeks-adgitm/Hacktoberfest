# Created a class Stack with instance variable initialized to an empty queue.
class Stack:
    def __init__(self):
        self.q = Queue()
 
# Defined methods enqueue, dequeue, is_empty and get_size inside the class Queue.
    def is_empty(self):
        return self.q.is_empty()
 
    def push(self, data):
        self.q.enqueue(data)
 
    def pop(self):
        for _ in range(self.q.get_size() - 1):
            dequeued = self.q.dequeue()
            self.q.enqueue(dequeued)
        return self.q.dequeue()

# Created a class Queue.
class Queue:
    def __init__(self):
        self.items = []
        self.size = 0

# The method is_empty returns True iff the queue is empty.'
    def is_empty(self):
        return self.items == []
 
# Pushing is done by enqueuing data to the queue.
    def enqueue(self, data):
        self.size += 1
        self.items.append(data)

# To pop, the queue is dequeued and enqueued with the dequeued element n - 1 times where n is the size of the queue. 
#This causes the the last element added to the queue to reach the rear of the queue. 
#The queue is dequeued one more time to get the item to be returned.
    def dequeue(self):
        self.size -= 1
        return self.items.pop(0)
 
    def get_size(self):
        return self.size
 
 
s = Stack()

print('------Menu-------')
print('Push <value>')
print('Pop')
print('Quit')
 
# The user is presented with a menu to perform push and pop operations on the stack.
# The chosen operation is performed by calling the corresponding method of the stack.
while True:
    do = input('What would you like to do from the above options? ').split()
 
    operation = do[0].strip().lower()
    if operation == 'push':
        s.push(int(do[1]))
    elif operation == 'pop':
        if s.is_empty():
            print('Stack is empty.')
        else:
            print('Popped value: ', s.pop())
    elif operation == 'quit':
        break
    