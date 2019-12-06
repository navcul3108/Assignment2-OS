#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	for(int i=0;i<MAX_QUEUE_SIZE;++i)
	{
		if(q->proc[i]==NULL)
		{
			q->proc[i]=proc;
			++q->size;
			return;
		}
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if(q->size!=0)
	{
		struct pcb_t* temp_proc;
		int max_priority=0;
		int max_idx=0;
		for(int i=0;i<MAX_QUEUE_SIZE;++i)
		{
			if(q->proc[i]!=NULL)
			{
				if(q->proc[i]->priority>max_priority)
				{
					temp_proc=q->proc[i];
					max_priority=temp_proc->priority;
					max_idx=i;
				}
			}
		}
		q->proc[max_idx]=NULL;
		--q->size;
		return temp_proc;
	}
	return NULL;
}

