//List.h interface file

typedef struct _list *List;

List newList(void);

void addNode(List l, int item);

void dropList(List l);