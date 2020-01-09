#include <iostream>
#include <cmath>
#include<climits> 

void swap(int*, int*);

class MinHeap{
	private:
		int* harr;
		int capacity = 0;
		int heap_size = 0;

	public:
		MinHeap(int size){

			harr = new int[size];
			capacity = size;
			heap_size = 0;
		}

		void display_heap(){
			for(int i=0;i<heap_size;i++){
				std::cout<<harr[i]<<" ";
			}
		}

		int parent(int i){
			return (i-1)/2;
		}

		int left_child(int i){
			return (2*i+1);
		}

		int right_child(int i){
			return 2*i+2;
		}

		void insert(int data);

		int poll();

};	

void MinHeap::insert(int data){
	if (heap_size == capacity){
		std::cout<<"Capacity Filled up"<<std::endl;
		return;
	}

	heap_size++;
	int i = heap_size - 1;
	harr[i] = data;

	while(i!=0 && harr[parent(i)] > harr[i]){
		swap(&harr[parent(i)],&harr[i]);
		i = parent(i);
	}

}

int MinHeap::poll(){
	int min_value = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;

	int i = 0;
	while((2*i + 1) < heap_size){
		int minChildindex = left_child(i);
		if(harr[left_child(i)]> harr[right_child(i)]){
			minChildindex = right_child(i);
		}

		swap(&harr[minChildindex],&harr[i]);
		i = minChildindex;
	}

	return min_value;

}


void swap(int* a, int* b){
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;

}

int main(int argc, char const *argv[])
{
	MinHeap min_heap(10);
	min_heap.insert(10);
	min_heap.insert(15);
	min_heap.insert(20);
	min_heap.insert(17);
	min_heap.insert(8);
	
	min_heap.display_heap();
	std::cout<<"\n"<<min_heap.poll()<<std::endl;
	min_heap.display_heap();
	//std::cout<<min_heap.extractMin();

	return 0;
}