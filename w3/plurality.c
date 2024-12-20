#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO string compare `name` against names of candidates in array, increment vote
    /*optimized version?
    - concatonate all candidate names
    - record first char position of each name
    - use substring comparison to get position of matching candidate
    - update cand vote count
    */
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO use selection sort to sort candidate array by vote count descending
    for (int i = 0; i < candidate_count - 1; i++)
    {
        // set max index to current position
        int max_idx = i;
        // search through unsorted portion to find max value
        for (int j = i; j < candidate_count; j++)
        {
            if (candidates[j].votes > candidates[max_idx].votes)
                max_idx = j;
        }
        // move min element to correct position
        candidate temp = candidates[i];
        candidates[i] = candidates[max_idx];
        candidates[max_idx] = temp;
    }

    // print winners of election
    int max_votes = candidates[0].votes;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!(candidates[i].votes == max_votes))
            break;
        printf("%s\n", candidates[i].name);
    }
    return;
}

