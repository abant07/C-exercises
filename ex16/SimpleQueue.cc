/*
 * Copyright ©2025 Hal Perkins.  All rights reserved.  Permission is
 * hereby granted to students registered for University of Washington
 * CSE 333 for use solely during Winter Quarter 2025 for purposes of
 * the course.  No other use, copying, distribution, or modification
 * is permitted without prior written consent. Copyrights for
 * third-party components of this work must be honored.  Instructors
 * interested in reusing these course materials should contact the
 * author.
 */

 #include "SimpleQueue.h"

 SimpleQueue::SimpleQueue() {
   size = 0;
   front = nullptr;
   end = nullptr;
   pthread_mutex_init(&pie_lock, NULL);
 }
 
 SimpleQueue::~SimpleQueue() {
   while (front != nullptr) {
     node *next = front->next;
     delete front;
     front = next;
   }
   pthread_mutex_destroy(&pie_lock);
 }
 
 void SimpleQueue::Enqueue(string item) {
  pthread_mutex_lock(&pie_lock);
   node *new_node = new node();
   new_node->next = nullptr;
   new_node->item = item;
   if (end != nullptr) {
     end->next = new_node;
   } else  {
     front = new_node;
   }
   end = new_node;
   size++;
   pthread_mutex_unlock(&pie_lock);
 }
 
 bool SimpleQueue::Dequeue(string *result) {
  pthread_mutex_lock(&pie_lock);
   if (size == 0) {
    pthread_mutex_unlock(&pie_lock);
     return false;
   }
   *result = front->item;
   node *next = front->next;
   delete front;
   if (end == front) {
     end = front = next;
   } else {
     front = next;
   }
   size--;
   pthread_mutex_unlock(&pie_lock);
   return true;
 }
 
 int SimpleQueue::Size() const {
  pthread_mutex_lock(&pie_lock);
   return size;
   pthread_mutex_unlock(&pie_lock);
 }
 
 bool SimpleQueue::IsEmpty() const {
  pthread_mutex_lock(&pie_lock);
   return size == 0;
   pthread_mutex_unlock(&pie_lock);
 }