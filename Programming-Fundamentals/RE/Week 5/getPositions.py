def get_positions(word_list, sentence):
    """
    get positions of the words of a sentence in the list
    """
    index0 = 0
    positions = ""

    #Creates every combination of sentences with the words in the list
    #Returns the positions of the words in the list on the first
    #correspondence to the sentence given
    for word0 in word_list:
        index1 = 0
        for word1 in word_list:
            if index0 != index1:
                combination = word0 + " " + word1
                if combination == sentence:
                    positions = str(index0) + " " + str(index1)
                    break
            index1 += 1
        if positions != "":
            break

        index0 += 1

    return positions
