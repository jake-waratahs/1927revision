//Queue.h implementation

typedef struct _queue *Queue;

#define TRUE 1
#define FALSE 0

//Make a new queue
Queue newQueue(void);

//Get an item
int queueLeave(Queue q);

//Add an item
void queueJoin(Queue q, int item);

//is the Queue empty?
int queueEmpty(Queue q);

//Kill the queue
void dropQueue(Queue q);

//Print the queue
void printQueue(Queue q);