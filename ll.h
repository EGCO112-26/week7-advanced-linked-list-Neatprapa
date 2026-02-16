#include <string.h>
// self-referential structure
struct Node {
   char name[50];
   int id; // each listNode contains a character
   struct Node *nextPtr; // pointer to next node
   struct Node *pPtr; //pointer to next node
}; // end structure listNode

typedef struct Node LLnode; // synonym for struct listNode
typedef LLnode *LLPtr; // synonym for ListNode*

// prototypes

//not edit
int isEmpty( LLPtr sPtr );
void instructions( void );
void printList( LLPtr currentPtr );
//edit
void insert( LLPtr *sPtr, int idvalue, char *namevalue );
int deletes( LLPtr *sPtr, int value );
void printListR( LLPtr currentPtr );

/* --for Assg 7--
1.print reverse
2.add a name
3.before end of prog dont forget to clear all node*/



// display program instructions to user
void instructions( void )
{
   puts( "Enter your choice:\n" /*puts คือ put string คล้ายกับ printf แต่แบบไม่มีตัวแปรใดๆ และ puts ขึ้น \n ให้อัตโนมัติ*/
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end." );
} // end function instructions

// insert a new value into the list in sorted order
void insert( LLPtr *sPtr, int idvalue, char *namevalue )
{
   LLPtr newPtr; // pointer to new node
   LLPtr previousPtr; // pointer to previous node in list
   LLPtr currentPtr; // pointer to current node in list

   newPtr =(LLPtr) malloc( sizeof( LLnode ) ); // create node

   if ( newPtr != NULL ) { // is space available
      newPtr->id=idvalue;
      strcpy(newPtr->name, namevalue);
      //newPtr->data = value; // place value in node
      newPtr->nextPtr = NULL; // node does not link to another node
      newPtr->pPtr=NULL;
    
      previousPtr = NULL;
      currentPtr = *sPtr;

      // loop to find the correct location in the list
      while ( currentPtr != NULL && idvalue > currentPtr->id ) {
         previousPtr = currentPtr; // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      } // end while

      // insert new node at beginning of list
      if ( previousPtr == NULL ) { /*for first node*/
         newPtr->nextPtr = *sPtr;/*ชี้ไป*/
         if(*sPtr!=NULL) (*sPtr)->pPtr=newPtr; /*ชี้กลับ ต้อง check ว่าไม่เท่ากับ NULL เพราะ NULL มันชี้กลับไม่ได้*/
         *sPtr = newPtr;
        
      } // end if
      else { // insert new node between previousPtr and currentPtr /*for other node*/
         previousPtr->nextPtr = newPtr;
         newPtr->pPtr=previousPtr;
         
         newPtr->nextPtr = currentPtr;
         if(currentPtr)currentPtr->pPtr=newPtr;
 
         
      } // end else
   } // end if
   else {
      printf( "%d not inserted. No memory available.\n", idvalue );
   } // end else
} // end function insert

// delete a list element
int deletes( LLPtr *sPtr, int value )
{
   LLPtr previousPtr; // pointer to previous node in list
   LLPtr currentPtr; // pointer to current node in list
   LLPtr tempPtr; // temporary node pointer

   // delete first node
   if ( value == ( *sPtr )->id) {
      tempPtr = *sPtr; // hold onto node being removed
      *sPtr = ( *sPtr )->nextPtr; // de-thread the node
      //(*sPtr)->pPtr=NULL;
      if(*sPtr!=NULL) (*sPtr)->pPtr=NULL;
      free( tempPtr ); // free the de-threaded node
      return value;
   } // end if
   else {
      previousPtr = *sPtr;
      currentPtr = ( *sPtr )->nextPtr;

      // loop to find the correct location in the list
      while ( currentPtr != NULL && currentPtr->id != value ) {
         previousPtr = currentPtr; // walk to ...
         currentPtr = currentPtr->nextPtr; // ... next node
      } // end while

      // delete node at currentPtr
      if ( currentPtr != NULL ) {
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr; //อย่าลืมเชื่อมกลับด้วย
         if(currentPtr->nextPtr!=NULL) currentPtr->nextPtr->pPtr=previousPtr;
         free( tempPtr );
         return value;
      } // end if
   } // end else

   return '\0';
} // end function delete

// return 1 if the list is empty, 0 otherwise
int isEmpty( LLPtr sPtr )
{
   return sPtr == NULL;
} // end function isEmpty

// print the list
void printList( LLPtr currentPtr )
{
   // if list is empty
   if ( isEmpty( currentPtr ) ) {
      puts( "List is empty.\n" );
   } // end if
   else {
      puts( "The list is:" );

      // while not the end of the list
      while ( currentPtr->nextPtr!= NULL ) {
         printf( "%d %s -->", currentPtr->id, currentPtr->name);
         currentPtr = currentPtr->nextPtr;
      } // end while

      printf( "%d %s -->NULL\n",currentPtr->id, currentPtr->name );
       

     
       
   } // end else
} // end function printList

void printListR( LLPtr currentPtr )
{
   //find "the last positon" before do anything!

   if ( isEmpty( currentPtr ) ) {
      puts( "List is empty.\n" );
   } // end if
   else {
      //puts( "The list is:" );

      while ( currentPtr->nextPtr!=NULL ) {
            //printf( "%d --> ", currentPtr->data );
            currentPtr = currentPtr->nextPtr;
         } // end while /*อันนี้คือการขยับไปตำแหน่งสุดท้าย(move currentPtr to the last node)*/

      while (currentPtr!=NULL ) {
         if(currentPtr->pPtr!=NULL) printf("%d %s -->",currentPtr->id, currentPtr->name);
         else printf("%d %s -->NULL\n",currentPtr->id, currentPtr->name);
         currentPtr = currentPtr->pPtr;
      }
   }      
}
