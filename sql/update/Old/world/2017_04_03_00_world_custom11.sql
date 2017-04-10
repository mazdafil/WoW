DELETE FROM `quest_template_addon` WHERE ID = 26237 OR ID = 26270 OR ID = 26241;
INSERT INTO `quest_template_addon` (`ID`, `NextQuestID`, ExclusiveGroup) VALUES (26237, 26270, -26237);
INSERT INTO `quest_template_addon` (`ID`, `NextQuestID`, ExclusiveGroup) VALUES (26241, 26270, -26237);
INSERT INTO `quest_template_addon` (`ID`, `NextQuestID`) VALUES (26270, 26266);
