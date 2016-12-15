from random import randint
from time import sleep

reward_table = [[-1 for x in range(16)] for x in range(16)]
q_matrix =     [[0 for  x in range(16)] for x in range(16)]

def set_up_reward_table():
    reward_table[0][1] =   0
    reward_table[0][4] =   0
    reward_table[1][0] =   0
    reward_table[2][3] =   0
    reward_table[2][6] =   0
    reward_table[3][2] =   0
    reward_table[3][7] =   0
    reward_table[4][0] =   0
    reward_table[4][8] =   0
    reward_table[5][6] =   0
    reward_table[5][9] =   0
    reward_table[6][2] =   0
    reward_table[6][5] =   0
    reward_table[7][3] =   0
    reward_table[7][11] =  0
    reward_table[8][4] =   0
    reward_table[8][9] =   0
    reward_table[8][12] =  0
    reward_table[9][8] =   0
    reward_table[9][5] =   0
    reward_table[9][13] =  0
    reward_table[9][10] =  0
    reward_table[10][9] =  0
    reward_table[10][14] = 0
    reward_table[11][7] =  0
    reward_table[11][15] = 100
    reward_table[12][8] =  0
    reward_table[13][9] =  0
    reward_table[13][14] = 0
    reward_table[14][10] = 0
    reward_table[14][13] = 0
    reward_table[14][13] = 0
    reward_table[15][11] = 0
    reward_table[15][15] = 100

def print_q_matrix():
    for each in q_matrix:
        print "{0:5.2f} {1:5.2f} {2:5.2f} {3:5.2f} {4:5.2f} {5:5.2f} {6:5.2f} {7:5.2f} {8:5.2f} {9:5.2f} {10:5.2f} {11:5.2f} {12:5.2f} {13:5.2f} {14:5.2f} {15:5.2f}".format(each[0], each[1], each[2], each[3], each[4], each[5], each[6], each[7], each[8], each[9], each[10], each[11], each[12], each[13], each[14], each[15])

def MAXQ(c):
    return max(q_matrix[c])

def Q(c, g):
    return q_matrix[c][g]

def R(c, g):
    return reward_table[c][g]

def qlearning():
    # 1. Set the gamma parameter, and environment rewards in matrix R.
    set_up_reward_table()
    # Gamma ranges from 0 to 1 - If Gamma is closer to one, the agent will consider future rewards with greater weight, willing to delay the reward.
    gamma = 0.9
    episodes = 10
    # 2. Initialize matrix Q to zero.

    # 3. For each episode (one episode = one training session)
    for each in range(episodes):
        print "Episode " + str(each)
        sleep(0.1)
    #    3.1 - Select random initial state
        initial_state = randint(0,15)
        current_state = initial_state
    #    3.2 - Do While the goal state hasn't been reached
        while(current_state != 15):
    #    3.3 - Select one among all possible actions for the current state
            possible_actions = {}
            for i in range(len(reward_table[current_state])):
                if (reward_table[current_state][i] >= 0):
                    possible_actions[i] = reward_table[current_state][i]
            possible_actions = possible_actions.items()
            # print possible_actions
            next_state = possible_actions[randint(0,len(possible_actions)-1)][0]
    #    3.4 - Consider going to the next state
            # print "moving from state " + str(current_state) + " to state " + str(next_state)
    #    3.5 - Get maximum Q value for this next state based on all possible actions
            maximum_q = MAXQ(next_state)
    #    3.6 - Compute Q(c_s, a_s) = R(a_s, g_s) + gamma * Max(Q(action_state, movements))
            q_matrix[current_state][next_state] = reward_table[current_state][next_state] + (gamma * maximum_q)
    #    3.7 - Set next state as current state
            current_state = next_state
    #    3.8 - End Do
    # 4. End for

def use_q_learning(initial_state):
    current_state = initial_state
    while(current_state != 15):

        # getting possible nodes
        possible_actions = {}
        for i in range(len(reward_table[current_state])):
            if (reward_table[current_state][i] >= 0):
                possible_actions[i] = reward_table[current_state][i]
        possible_actions = possible_actions.items()

        possible_nodes = []
        for each in possible_actions:
            possible_nodes.append(each[0])

        best_node = possible_nodes[0]
        for each in possible_nodes:
            if (Q(current_state,each) > Q(current_state, best_node)):
                best_node = each

        print "moving from " + str(current_state) + " to " + str(best_node)
        current_state = best_node

        '''
        for i in range(len(q_matrix)):
            if (q_matrix[current_state][i] > q_matrix[current_state][best_pos]):
                best_pos = i
            print "moving from " + str(current_state) + " to " + str(best_pos)
            current_state = best_pos
        '''



if __name__ == '__main__':
    print "Q Matrix Before Q Learning:"
    print_q_matrix()
    print "Executin Q Learning..."
    qlearning()
    print "Q Matrix after Q Learning:"
    print_q_matrix()
    print "Reward Matrix:"
    for each in reward_table:
        print each
    print "=============================================="
    print "Using Q Matrix to go from 9 to 15: "
    # use_q_learning(9)
