#include <stdio.h>
void take_input();
int has_one_pair(int player);
int has_three_of_kind(int x, int y, int z);
int has_two_pair(int player);
int has_three_of_a_kind(int player);
int has_straight(int player);
int has_flush(int player);
int has_full_house(int player);
int has_four_of_a_kind(int player);
int has_straight_flush(int player);
int evaluate_player_hand(int player);
int determine_winner();
struct card
{
    char suit;
    int rank;
};
struct card game_cards[10];
void take_input()
{
    printf("Please enter details of cards\n");
    scanf("%d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c",
          &game_cards[0].rank, &game_cards[0].suit,
          &game_cards[1].rank, &game_cards[1].suit,
          &game_cards[2].rank, &game_cards[2].suit,
          &game_cards[3].rank, &game_cards[3].suit,
          &game_cards[4].rank, &game_cards[4].suit,
          &game_cards[5].rank, &game_cards[5].suit,
          &game_cards[6].rank, &game_cards[6].suit,
          &game_cards[7].rank, &game_cards[7].suit,
          &game_cards[8].rank, &game_cards[8].suit,
          &game_cards[9].rank, &game_cards[9].suit);
    for (int i = 0; i < 10; i++)
    {
        if (game_cards[i].rank == 1)
        {
            game_cards[i].rank = 14;
        }
    }
}
int has_one_pair(int player)
{
    int start_index = (player == 1) ? 0 : 5;
    int end_index = start_index + 5;

    for (int i = start_index; i < end_index; i++)
    {
        for (int j = i + 1; j < end_index; j++)
        {
            if (game_cards[i].rank == game_cards[j].rank)
            {
                return 1;
            }
        }
    }
    return 0;
}
int has_three_of_kind(int x, int y, int z)
{
    return (x == y || x == z || y == z);
}
int has_two_pair(int player)
{
    int start_index = (player == 1) ? 0 : 5;
    int end_index = start_index + 5;
    for (int i = start_index; i < end_index; i++)
    {
        for (int j = i + 1; j < end_index; j++)
        {
            if (game_cards[i].rank == game_cards[j].rank)
            {
                for (int k = start_index; k < end_index; k++)
                {
                    if (k != i && k != j)
                    {
                        for (int l = k + 1; l < end_index; l++)
                        {
                            if (game_cards[k].rank == game_cards[l].rank)
                            {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int has_three_of_a_kind(int player)
{
    int start_index = (player == 1) ? 0 : 5;
    int end_index = start_index + 5;
    for (int i = start_index; i < end_index; i++)
    {
        for (int j = i + 1; j < end_index; j++)
        {
            if (game_cards[i].rank == game_cards[j].rank)
            {
                for (int k = j + 1; k < end_index; k++)
                {
                    if (game_cards[j].rank == game_cards[k].rank)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
int has_straight(int player)
{
    int start_index = (player == 1) ? 0 : 5;
    int end_index = start_index + 5;
    for (int i = start_index; i < end_index - 1; i++)
    {
        for (int j = start_index; j < end_index - i - 1; j++)
        {
            if (game_cards[j].rank > game_cards[j + 1].rank)
            {
                struct card temp = game_cards[j];
                game_cards[j] = game_cards[j + 1];
                game_cards[j + 1] = temp;
            }
        }
    }
    for (int i = start_index; i < end_index - 1; i++)
    {
        if (game_cards[i + 1].rank - game_cards[i].rank != 1)
        {
            return 0;
        }
    }
    return 1;
}
int has_flush(int player)
{
    int start_index = (player == 1) ? 0 : 5;
    int end_index = start_index + 5;

    char suit = game_cards[start_index].suit;
    for (int i = start_index + 1; i < end_index; i++)
    {
        if (game_cards[i].suit != suit)
        {
            return 0;
        }
    }
    return 1;
}
int has_full_house(int player)
{
    return (has_three_of_a_kind(player) && has_one_pair(player));
}
int has_four_of_a_kind(int player)
{
    int start_index = (player == 1) ? 0 : 5;
    int end_index = start_index + 5;

    for (int i = start_index; i < end_index; i++)
    {
        for (int j = i + 1; j < end_index; j++)
        {
            if (game_cards[i].rank == game_cards[j].rank)
            {
                for (int k = j + 1; k < end_index; k++)
                {
                    if (game_cards[j].rank == game_cards[k].rank)
                    {
                        for (int l = k + 1; l < end_index; l++)
                        {
                            if (game_cards[k].rank == game_cards[l].rank)
                            {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int has_straight_flush(int player)
{
    return (has_straight(player) && has_flush(player));
}
int evaluate_player_hand(int player)
{
    if (has_straight_flush(player))
    {
        return 9;
    }
    else if (has_four_of_a_kind(player))
    {
        return 8;
    }
    else if (has_full_house(player))
    {
        return 7;
    }
    else if (has_flush(player))
    {
        return 6;
    }
    else if (has_straight(player))
    {
        return 5;
    }
    else if (has_three_of_a_kind(player))
    {
        return 4;
    }
    else if (has_two_pair(player))
    {
        return 3;
    }
    else if (has_one_pair(player))
    {
        return 2;
    }
    else
    {
        return 1;
    }
}
int determine_winner()
{
    int player1_score = evaluate_player_hand(1);
    int player2_score = evaluate_player_hand(2);

    if (player1_score > player2_score)
    {
        return 1;
    }
    else if (player1_score < player2_score)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
int main()
{
    take_input();
    int winner = determine_winner();
    if (winner == 0)
    {
        printf("It's a tie!\n");
    }
    else
    {
        printf("Player %d wins!\n", winner);
    }
    return 0;
}