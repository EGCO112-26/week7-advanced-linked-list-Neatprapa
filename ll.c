// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>//อย่างอันนี้คือค้นหาที่ libary
#include "ll.h" //มันค้นหาคนละที่กันเลลยใช่ <> ไม่ได้
/*startPtr อยู่ใน main SPtr อยู่ในฟังก์ชัน*/
int main( void )
{ 
   LLPtr startPtr = NULL; // initially there are no nodes /*ตอนเริ่มต้นไม่มีnodeใดๆ*/
   unsigned int choice; // user's choice /*unsigned ไม่รับค่าลบ*/
   int item; // char entered by user

   instructions(); // display the menu
   printf( "%s", "? " );
   scanf( "%u", &choice );

   // loop while user does not choose 3
   /*ถ้าเลขอื่นจะขึ้น instruction ใหม่*/
   while ( choice != 3 ) { 

      switch ( choice ) { 
         case 1:
            printf( "%s", "Enter a number: " );
            scanf( "%d", &item );
            insert( &startPtr, item ); // insert item in list
            printList( startPtr );
            break;
         case 2: // delete an element
         /*check is it empty?--> if it's not empty ask the number --> delete that number --> show the list of number*/
            // if list is not empty
            if ( !isEmpty( startPtr ) ) { 
               printf( "%s", "Enter number to be deleted: " );
               scanf( "%d", &item );

               // if character is found, remove it
               if ( deletes( &startPtr, item ) ) { // remove item
                  printf( "%d deleted.\n", item );
                  printList( startPtr );
               } // end if
               else {
                  printf( "%d not found.\n\n", item );
               } // end else
            } // end if
            else {
               puts( "List is empty.\n" );
            } // end else

            break;
         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      } // end switch

      printf( "%s", "? " );
      scanf( "%u", &choice );
   } // end while
  /* Clear all nodes at the end of nodes*/
   puts( "End of run." );
} // end main
