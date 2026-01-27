#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void merge_sort(int start, int end, pair *pairs); // ADDED

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
           ranks[rank] = i;
           return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
                preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // SELECTION SORT
    for (int i = 0; i < pair_count; i++)
    {
        int stronger_index = i;

        for (int j = i + 1; j < pair_count; j++)
        {
            if (preferences[pairs[stronger_index].winner][pairs[Stronger_index].loser] < preferences[pairs[j].winner][pairs[j].loser])
            {
                stronger_index = j;
            }
        }
        if(stronger_index != i) // Prevents that the swap occurs even if the first element in 'i' is already the stronger one. In other words, it prevents to swap with itself
        {
            pair temporary = pairs[i];
            pairs[i] = pairs[stronger_index];
            pairs[stronger_index] = temporary;
        }
    }
    return;

    /*BUBBLE SORT
    bool swaps = false; // Will check the first iteration to see if there was no swaps among the elements
    pair stronger = pairs[0];
    for (int i = 0; i < pair_count - 1; i++) // First loop will go through all elements in the array lots of times
    {
        for (int j = 0; j < pair_count - i - 1; j++) // Second loop will do the swaps
        //Subtract 'i' and '1' from pair_count. '1' because j+1 can't be equal to "pair_count". 'i' so that it doesn't goes to the last elements that are already beaing sorted
        {
            if (preferences[pairs[j].winner][pairs[j].loser] < preferences[pairs[j + 1].winner][pairs[j + 1].loser])
            {
                stronger = pairs[j + 1];
                pairs[j + 1] = pairs[j];
                pairs[j] = stronger;
                swaps = true; // Will assure that a swap will occur.
            }
        }
        if (!swaps) // If no swaps in the first iteration, we won't add +1 on the 'i' variable. This if condition will jsut exit the function because the array is already sorted
        {
            return;
        }
    }
    return;
    */

    //MERGE SORT -> Couldn't do it! Very hard and complex for a begginer to implement.
    // merge_sort(0, pair_count - 1, pairs);

}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void) // ALso, couldn't do that. Will need to improve my recursive logic to dive into this code
{

}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}
