//problem=> https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem?isFullScreen=true

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    //ilk olarak ekleyecegimiz yeri bilmemiz gerekir.
    //istisna olarak eklenecek eleman tum elemanlardan kucuk olabilir bu durumda:
    if(data < llist->data){
        DoublyLinkedListNode *node = (DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
        node->data = data;
        node->prev = NULL;
        llist->prev = node;
        node->next = llist;
        return node;
        
    }
    DoublyLinkedListNode *head = llist;
    while (head != NULL) {
        if(head->next == NULL){
            //sona kadar eklenmediyse direk eklenmelidir.
            head->next = (DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
            head->next->data = data;
            head->next->next = NULL;
            head->next->prev = head;
            return llist;
        }
        if(head->data <= data && head->next->data >= data){
            //eklenecek ara bulunmustur.
            DoublyLinkedListNode *devam_tut = head->next;
            head->next = (DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));
            head->next->data = data;
            head->next->prev = head;
            head->next->next = devam_tut;
            return llist;
        }
        head = head->next;
    }
    return head;
}