DELETE FROM `creature_template` WHERE entry = 119704;
INSERT INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `femaleName`, `subname`, `IconName`, `type`, `type_flags`, `VerifiedBuild`) VALUES ('119704', '1126', '75463', 'Scout through the Jasperlode Mine done.', ' ', '', '', '10', '1024', '23420');
DELETE FROM `creature_template_locale` WHERE entry = 119704;
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `TitleAlt`) VALUES ('119704', 'ruRU', 'Разведка в Яшмовой шахте проведена.', NULL, NULL);
UPDATE `quest_template` SET Flags = 8 WHERE ID = 76;
UPDATE `quest_template_addon` SET SpecialFlags = 0 where ID = 76;
UPDATE `quest_objectives` SET Type = 0, ObjectID = 119704, Amount = 1, Flags = 1 WHERE QuestID = 76;
DELETE FROM `areatrigger_scripts` WHERE entry = 87;
INSERT INTO `areatrigger_scripts` VALUES (87, 'at_jasperlode_mine');
