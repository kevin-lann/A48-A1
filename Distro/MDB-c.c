/*
 *  CSC A48 - Winter 2023 - Assignment 1 starter
 * 
 *  (c) 2020-23 Francisco Estrada
 *  - No part of this code may be reproduced without written authorization
 * 
 * This is the file where you will be doing most of your work. The
 * functionality you must provide for part 1 of the assignment is described
 * in the handout. Given in detail in the comments at the head of each
 * function below. 
 * 
 * Plan your work carefully, review the notes for Unit 3, and work carefully
 * to complete the functions in this file. You can bring 
 * questions to your TAs or instructors during office hours. Please
 * remember:
 * 
 * - You should not share any part of your solution in any form
 * - You should not post any assignment code on Piazza
 * - You should definitely *help* other understand any ideas and
 *   concepts regarding linked lists that you have already mastered,
 *   but being careful not to give away parts of the solution, or
 *   descriptions of how to implement functions below.
 * - If you are not sure whether you can or can not discuss some
 *   particular aspect of the work to be done, remember it's always 
 *   safe to talk with your TAs.
 * - Obtaining external 'help' including being given code by an
 *   external party, or being tutored on how to solve
 *   the assignment constitutes an academic offense.
 * 
 * All tasks to be completed by you are clearly labeled with a
 * ***** TO DO ****** comment block, which also gives you details
 * about what you have to implement. Look carefully and make sure
 * you don't miss a thing!
 * 
 * NOTE: This file contains no main() function! you can not compile
 * it on its own to create an executable. It's meant to be used
 * together with Part1_driver.c - be sure to read that file carefully
 * to understand how to use the tests there - Any additional tests
 * you want to run on the code below should be added to Part1_driver.c
 * 
 * Before you even get starter implementing, please complete the
 * student identification section below, and check that you are aware
 * of the policy on academic honesty and plagiarism.
 */

/* Student identification:
 * 
 * Student Name (Last name, First name): Lan, Kevin
 * Student Number: 1009407143
 * UTORid: lankevin
 * Your instructor's name is: Marcelo Ponce
 */

/* Academic Integrity Statement:
 * 
 * I hereby certify that the work contained in this file is my own, and
 * that I have not received any parts of my solution from other sources
 * including my fellow students, external tutoring services, the internet,
 * or algorithm implementations found online.
 * 
 * Sign here with your name:
 * Kevin Lan
 *  
 */

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024

/* Compound data type declarations */
/***************************************************************************/
/******                         TO DO                               ********/
/****** In the space below, complete the definitions of the compound *******/
/****** data types that will be needed to implement the movie review *******/
/****** linked list. This includes the MovieReview type, and the     *******/
/****** ReviewNode. Details about the contents of these can be       *******/
/****** found in the assignment handout. Read them carefully!        *******/
/******                                                              *******/
/****** AFTER completing the basic linked list, complete the CDT     *******/
/****** required to implement a list for the movie's cast.           *******/
/***************************************************************************/

typedef struct castList_struct
{    
	char name[MAX_STR_LEN];
	float salary;	//how much the cast member was paid from this movie
	struct castList_struct *next;
    
} CastList;

typedef struct movieReview_struct
{
	char movie_title[MAX_STR_LEN];
	char movie_studio[MAX_STR_LEN];
    int year; // an int in range 1920 - 2999
	float BO_total;
	int score; // an int in range 0-100;
	CastList *cast;
	
} MovieReview;

typedef struct reviewNode_struct
{
	MovieReview review;
	struct reviewNode_struct *next;
    
} ReviewNode;

typedef struct cast_to_avg_earnings_node_struct
{
    char name[MAX_STR_LEN];
    float total;
    int num_movies;
    struct cast_to_avg_earnings_node_struct *next;
} CastEarningsNode;

ReviewNode* insert_at_head(ReviewNode *head, ReviewNode *new){
	new->next = head;
	return new;
}

ReviewNode* delete_head(ReviewNode **head) {
	ReviewNode * temp = *head;
	*head = (*head)->next;
	free(temp);
	return *head;
}

void delete_end(ReviewNode *head){
	ReviewNode * end = head;
	ReviewNode * prev = NULL;
	while(end->next != NULL){
		prev = end;
		end = end->next;
	}
	// by the end of this loop, prev will refer to 2nd last and end will refer to last
	prev->next = NULL;
	free(end);
}

void delete_middle(ReviewNode *head, ReviewNode *node) {
	while(head->next != NULL) {
		// if next node is the right node, then make current node point to next next node
		if (head->next == node) {
			head->next= node->next;
			free(node);
			break;
		}
		else head = head->next;
	}
}


ReviewNode *newMovieReviewNode()
{
    /*
     * This function allocates an empty ReviewNode, and initializes the
     * contents of the MovieReview for this node to reasonable (uninitialized) values.
     * The fields in the MovieReview should be set to:
     *  movie_title=""
     *  movie_studio=""
     *  year = -1
     *  BO_total = -1
     *  score = -1
     *  scoreList = NULL;
     * 
     * The *next pointer for the new node MUST be set to NULL
     * 
     * The function must return a pointer to the newly allocated and initialized
     * node. If something goes wrong, the function returns NULL
     */
 
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *new_node=NULL;
	
	new_node = (ReviewNode*)calloc(1, sizeof(ReviewNode));
	
	strcpy(new_node->review.movie_title, "");
	strcpy(new_node->review.movie_studio, "");
	new_node->review.year = -1;
	new_node->review.BO_total = -1;
	new_node->review.score = -1;
	new_node->review.cast = NULL;
    // new_node->review.cast = (CastList*)calloc(1, sizeof(CastList));
    
    return(new_node);    
}

ReviewNode *findMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
    /*
     * This function searches through the linked list for a review that matches the input query. 
     * The movie review must match the title, studio, and year provided in the 
     * parameters for this function.
     * 
     * If a review matching the query is found, this function returns the address of the node that
     * contains that review. 
     * 
     * If no such review is found, this function returns NULL
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
	// traverse list and if review found, then return its address
	while(head != NULL){
		if(strcmp(title, head->review.movie_title) == 0
			&& strcmp(studio, head->review.movie_studio) == 0
			&& year == head->review.year){
				return head;
		}
		head = head->next;
	}
	
	// return NULL if cannot find
    return NULL;  
}

ReviewNode *insertMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function inserts a new movie review into the linked list.
     * 
     * The function takes as input parameters the data neede to fill-in the review,
     * as well as apointer to the current head of the linked list.
     * 
     * If head==NULL, then the list is still empty.
     * 
     * The function inserts the new movie review *AT THE HEAD* of the linked list,
     * and returns the pointer to the new head node.
     * 
     * The function MUST check that the movie is not already in the list before
     * inserting (there should be no duplicate entries). If a movie with matching
     * title, studio, and year is already in the list, nothing is inserted and the
     * function returns the current list head.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
	// check if a copy already in the list
	if (findMovieReview(title, studio, year, head) != NULL){
		printf("This movie is already in the Database\n");
		return head;
	}
	
	ReviewNode *new_node = NULL;
	new_node = (ReviewNode*)calloc(1, sizeof(ReviewNode));
	
	strcpy(new_node->review.movie_title, title);
	strcpy(new_node->review.movie_studio, studio);
	new_node->review.year = year;
	new_node->review.BO_total = BO_total;
	new_node->review.score = score;
    new_node->review.cast = NULL;
    // new_node->review.cast = (CastList*)calloc(1, sizeof(CastList));
	
    return insert_at_head(head, new_node);        
}

int countReviews(ReviewNode *head)
{
  /*
   * This function returns the number of reviews. 
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    int count = 0;
	
	while(head != NULL) {
		count++;
		head = head->next;
	}
	
    return count;   
}

void updateMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function looks for a review matching the input query [title, studio, year].
     * If such a review is found, then the function updates the Box-office total, and the score.
     * If no such review is found, the function prints out 
     * "Sorry, no such movie exists in the database"
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
	ReviewNode * node = findMovieReview(title, studio, year, head);
	if (node != NULL) {
		node->review.BO_total = BO_total;
		node->review.score = score;
	}
	// no such review is found
	else printf("Sorry, no such movie exists in the database\n");
}

ReviewNode *deleteMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN],int year, ReviewNode *head)
{
    /*
     * This function removes a review matching the input query from the database. If no such review can
     * be found, it does nothing.
     * 
     * The function returns a pointer to the head of the linked list (which may have changed as a result
     * of the deletion process)
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
	ReviewNode ** ptp_head = &head;
	ReviewNode * node = NULL;
	node = findMovieReview(title, studio, year, head);
	
	// node is head node
	if (node == head) head = delete_head(ptp_head);
	// node is end node
	else if(node->next == NULL) delete_end(head);
	// node is somewhere in between head and end nodes
	else delete_middle(head, node);
	
	free(node);
        
    return head;
}

void printReview(ReviewNode* node) {
	/*
	* This function prints out a single review. Helper function for printMovieReviews() 
	* and queryReviewsByStudio().
	*/
	printf("%s\n\n", node->review.movie_title);
	printf("%s\n\n", node->review.movie_studio);
	printf("%d\n%f\n%d\n", node->review.year, node->review.BO_total, node->review.score);
	printf("*******************\n");
}

float printMovieReviews(ReviewNode *head)
{
    /*
     * This function prints out all the reviews in the database, one after another.
     * Each field in the review is printed in a separate line, with *no additional text*
     * (that means, the only thing printed is the value of the corresponding field).
     * 
     * Reviews are separated from each other by a line of
     * "*******************"

     * The function also computes and returns the Box-office total, for all the
     * movies that match the query.
     * 
     * See the A1 handout for a sample of the output that should be produced
     * by this function
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
	float total_BO = 0;
	
	while(head != NULL) {
		printReview(head);
		total_BO += head->review.BO_total;
		head = head->next;
	}
	 
    return total_BO;
}

float queryReviewsByStudio(char studio[MAX_STR_LEN], ReviewNode *head)
{
    /*
     * This function looks for reviews whose studio matches the input query.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    
    float total_BO = 0;
	
	while(head != NULL) {
		if (strcmp(head->review.movie_studio, studio) == 0){
			printReview(head);
			total_BO += head->review.BO_total;
		}
		head = head->next;
	}
	 
    return total_BO;
}

float queryReviewsByScore(int min_score, ReviewNode *head)
{
    /*
     * This function looks for reviews whose score is greater than, or equal to
     * the input 'min_score'.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     * 
     * Additionally, it computes and returns the Box-office total, for all the
     * movies that match the query.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  
    
    float total_BO = 0;
	
	while(head != NULL) {
		if (head->review.score >= min_score){
			printReview(head);
			total_BO += head->review.BO_total;
		}
		head = head->next;
	}
	 
    return total_BO;
}

ReviewNode *deleteReviewList(ReviewNode *head)
{
  /*
   * This function deletes the movie review database, releasing all the
   * memory allocated to the nodes in the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   */
      
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/    

    ReviewNode * prev = NULL;
	while(head != NULL) {
		prev = head;
		head = head->next;
		free(prev);
	}
	
    return head;      
}

void printNames(ReviewNode *movie)
{
    // prints out names of cast members for this movie
    CastList *p;
    if (movie==NULL||movie->review.cast==NULL) return;

    p=movie->review.cast;
    printf("The cast for this movie are:\n");
    while (p!=NULL)
    {
        printf("Cast Member: %s, Salary: %f\n",p->name,p->salary);
        p=p->next;
    }
}

/* CRUNCHY SECTION! Do not work on the functions below until
 * your basic linked list is working properly and is fully tested!
 */ 

// Helper for sortReviewsByTitle
void swapNodes(ReviewNode *n1, ReviewNode *n2) {
	/*
	* This function "swaps" two nodes in the list by swapping the reviews each of them points to.
	*/
	MovieReview temp = n1->review;
	n1->review = n2->review;
	n2->review = temp;
}

ReviewNode *sortReviewsByTitle(ReviewNode *head)
{
  /*
   * This function sorts the list of movie reviews in ascending order of movie
   * title. If duplicate movie titles exist, the order is arbitrary (i.e. you
   * can choose which one goes first).
   * 
   * However you implement this function, it must return a pointer to the head
   * node of the sorted list.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      
    
	int len = countReviews(head);
	ReviewNode * cur = head;
	
	for (int i = 0; i < len; i++) {
        cur = head;
		for(int j = 0; j < len - i - 1; j++){
            if(strcmp(cur->next->review.movie_title, cur->review.movie_title) < 0) swapNodes(cur, cur->next);
			cur = cur->next;
		}
	}
	
    return head;  
}

// Helper for insertCastMember
CastList * insertCastNodeBySalary(float salary, char name[MAX_STR_LEN], CastList * head){

    CastList * cur = head;

    // initialize
    CastList * node = NULL;
    node = (CastList*)calloc(1, sizeof(CastList));
    strcpy(node->name, name);
    node->salary = salary;

    // if nessacary, insert at head
    if (head->salary < salary){
        node->next = head;
        return node;
    }
    //else find spot to insert
    while(cur != NULL && cur->salary > salary) {
        if(cur->next == NULL || cur->next->salary <= salary) {
            // spot found
            break;
        }
        cur = cur->next;
    }
    
    // insert
    CastList * temp = cur->next;
    cur->next = node;
    node->next = temp;
    return head;
}

void insertCastMember(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, ReviewNode *head, char name[MAX_STR_LEN], float salary)
{
  /*
   * This function inserts the name of a cast member for the given movie into the
   * linked list of cast members. XXXXXXXXXXXXXX (OMIT) The new cast member must go to the end of the list. (OMIT) XXXXXXXXXXX
   * 
   * Duplicate names are allowed - this time! 
   * 
   * Notice the function receives the title, studio, and year for the movie, as
   * well as a pointer to the movie DB linked list. The function must find the 
   * correct movie and if such a movie exists, add the cast member's name to its
   * cast list.
   * 
   * If no such movie is found, this function does nothing.
   * 
   * You're free to add helper functions to insert the cast member's name
   * into the cast list.
   */   

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      
  
    ReviewNode * node = findMovieReview(title, studio, year, head);
    // Check if movie can be found
    if (node != NULL) {
        // CastList * c = node->review.cast;
        // empty list, then initialize and insert at the head
        if(node->review.cast == NULL) {
            // c = (CastList*) calloc(1, sizeof(CastList));
            CastList * new_cast = NULL;
            new_cast = (CastList*) calloc(1, sizeof(CastList));
            strcpy(new_cast->name, name);
            new_cast->salary = salary;
            
            new_cast->next = node->review.cast;
            node->review.cast = new_cast;
        }
        // nonempty list, then find correct position and insert
        else{
            node->review.cast = insertCastNodeBySalary(salary , name, node->review.cast);
        }
    }
}

// Helper for whosTheStar
float sumAllSalaries(MovieReview movie)
{
    /**
     * THis function calculates the total spent on paying salaries of all the cast members of the given movie
    */
    CastList * cast = movie.cast;
    float total_paid = 0;

    while(cast != NULL) {
        total_paid += cast->salary;
        cast = cast->next;
    }

    return total_paid;
}

// Helper for whosThestar
int findCast(char name[MAX_STR_LEN], CastEarningsNode* cast_list) {
    /**
     * This function returns 1 if the given cast member name is already in cast_list and 0 if not
    */
    while (cast_list != NULL) {
        if (strcmp(name, cast_list->name) == 0) return 1;
        cast_list = cast_list->next;
    }
    return 0;
}

// Helper for whosThestar
CastEarningsNode * insert_cast_earnings(char name[1024], float earnings, CastEarningsNode * cast_list){
    /**
     * This function inserts a new cast to earnings key value pair at the head of the cast_list and returns the head
    */
   CastEarningsNode * new_node = NULL;
   new_node = (CastEarningsNode*)calloc(1, sizeof(CastEarningsNode));

   strcpy(new_node->name, name);
   new_node->total = earnings;
   new_node->num_movies = 1;
   new_node->next = cast_list;

   return new_node;
}

// Helper for whosTheStar
void update_cast_earnings(char name[1024], float earnings, CastEarningsNode * cast_list){
    /**
     * This function updates the total earnings and num movies fields of a cast member given by name in cast_list.
    */
    while(cast_list != NULL){
        if (strcmp(name, cast_list->name) == 0){
            break;  // cast member found
        }
        cast_list = cast_list->next;
    }
    cast_list->total += earnings;
    cast_list->num_movies += 1;
}

void whosTheStar(ReviewNode *head)
{
  /*
   *  This function goes through the movie database and determines who is
   * the cast members whose movies have the greatest average earnings.
   *
   * Earnings are defined as the box office total minus the salaries of all
   * cast members involved with the movie.
   *
   *  You're free to implement this function however you like, use any of
   * the code you wrote for other parts of the assignment, and write any
   * helper functions that you need. But:
   *
   *  You can not import extra libraries (no additional #include), and
   * all the implementation here should be your own. 
   *
   *  The function simply prints out:
   *
   *  Name of cast member
   *  Average movie earnings (as a floating point number)
   *
   *  For the cast member whose movies make the greatest average earnings
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      


    ReviewNode * cur = head;
    CastEarningsNode * cast_earnings = NULL;
    

    // loop through every movie
    while(cur != NULL){
        // Call fn to calculate movie total earnings (Earnings = BO_total - all salaries)
        float earnings = cur->review.BO_total - sumAllSalaries(cur->review);
        //find cast members
        CastList * cast = cur->review.cast;
        while (cast != NULL) {
            // check if they are unique, if yes then add a new node to CastEarnings list and add info
            if(findCast(cast->name, cast_earnings) == 0) {
                cast_earnings = insert_cast_earnings(cast->name, earnings, cast_earnings);
            }
            // if not unique, then just update info
            else{
                update_cast_earnings(cast->name, earnings, cast_earnings);
            }
            cast = cast->next;
        }
        cur = cur->next;
    }
    // if no cast members found, then return (nothing is printed)
    if (cast_earnings == NULL) return;

    // Go once more through the CastEarnings list and calculate avg for each cast member, while recording the largest average
    float max_avg = 0;
    char max_name[MAX_STR_LEN];
    while(cast_earnings != NULL) {
        float avg = cast_earnings->total / cast_earnings->num_movies;
        // printf("%s: total = $%f, num movies = %d, avg = %f \n", cast_earnings->name, cast_earnings->total, cast_earnings->num_movies, avg);
        if(avg > max_avg){
            max_avg = avg;
            strcpy(max_name, cast_earnings->name);
        } 
        cast_earnings = cast_earnings->next;
    }
    // Print out highest earning cast member name and their associated average earnings of movies they are associated with
    printf("%s\n%f\n", max_name, max_avg);

}




// REMOVE LATER
/* int main(){
    
	ReviewNode *head = NULL;
	head = insertMovieReview("aa", "zamzam", 1999, 10000, 15, head);
    head = insertMovieReview("aa", "zam", 1999, 10000, 15, head);
	head = insertMovieReview("bb", "ssss", 1999, 10000, 68, head);
    head = insertMovieReview("cc", "zamzam", 1999, 10000, 68, head);
	head = insertMovieReview("dd", "zamzam", 1999, 10000, 20, head);
    head = insertMovieReview(" ", "zamzam", 1999, 10000, 68, head);
	
    //CastList * cast = head->review.cast;
    
    head = sortReviewsByTitle(head);
    printf("$%f\n", total);
    
    //while(cast != NULL) {
        //printf("\n%s, %f\n", cast->name, cast->salary);
        //cast = cast->next;
    //}
} */
