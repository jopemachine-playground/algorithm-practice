#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int result = 0;
    bool hasTheSkill[26] = { false, };

    for (int i = 0; i < skill.size(); ++i) {
        hasTheSkill[skill.at(i) - 'A'] = true;
    }

    for (int i = 0; i < skill_trees.size(); ++i) {
        // 0 = skill not exists, 1 = learned the skill, -1 = not learned
        int skillLearned[26] = { 0, };
        bool preSkillNotLearned = false;
        for (int j = 0; j < skill_trees[i].size(); ++j) {
            if (hasTheSkill[skill_trees[i].at(j) - 'A'] == true) {
                int k = 0;
                // repeat until finding the skill
                while (k < skill.size() && k < skill_trees[i].size() && skill.at(k) != skill_trees[i].at(j)) {
                    if (hasTheSkill[skill.at(k) - 'A'] == true && skillLearned[skill.at(k) - 'A'] == 0) {
                        preSkillNotLearned = true;
                        break;
                    }
                    ++k;
                }

                if (preSkillNotLearned) break;
                else {
                    skillLearned[skill_trees[i].at(j) - 'A'] = 1;
                }
            }
        }
        if (!preSkillNotLearned) ++result;
    }

    return result;
}