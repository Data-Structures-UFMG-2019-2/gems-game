# Gems Game

It is not always easy to envision an efficient solution to some complex problems. Sometimes, even if such a solution exists, it is necessary to visualize the big picture in a different way, and this is the approach of dynamic programming, to reduce a complex problem for which we do not have immediate solution to a set of smaller problems that are easier to solve. The following statement presents a particular case of a problem that can be solved using such strategies, we will see an applicable solution that makes use of dynamic programming and discuss its advantages and disadvantages.

Adriana is a very famous goldsmith and known for her eccentricities. Extremely methodical, whenever she receives a pouch with diamonds, she performs the same procedure before creating her jewelry. She makes the so-called Diamond Game for each pouch. The diamond game assumes that for a collection of stones, any two stones can be "combined". Suppose we have two stones with weights and p<sub>1</sub> and p<sub>2</sub> with p<sub>1</sub> >= p<sub>2</sub> the result of this operation could be:

* If p<sub>1</sub> == p<sub>2</sub>, both stones are completely destroyed.
* If p<sub>1</sub> > p<sub>2</sub> , the stone p<sub>1</sub> remains with a new weigth p<sub>1</sub> - p<sub>2</sub> and p<sub>2</sub> is completely destroyed.

The game ends when there is one or no stones left in the set, and the goal is for the remaining weight to be as small as possible (if there is no stones left, the remaining weight is zero).