#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t* q) {
	if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t* q, struct pcb_t* proc) {
	/* TODO: put a new process to queue [q] */
	if (q == NULL || proc == NULL) return; // check for null pointers
	if (q->size >= MAX_QUEUE_SIZE) return; // check if queue is full
	q->proc[q->size++] = proc; // add process to end of queue and increment size
}

struct pcb_t* dequeue(struct queue_t* q) {
	/* TODO: return a pcb whose priority is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (q->size == 0) return NULL;
	struct pcb_t* reItem = q->proc[0];

	for (int i = 0; i < (q->size - 1); i++) {
		q->proc[i] = q->proc[i + 1];
	}

	q->size--;
	return reItem;
}