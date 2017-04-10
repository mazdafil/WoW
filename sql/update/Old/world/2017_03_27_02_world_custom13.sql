DELETE FROM `creature_template` WHERE entry = 119703;
INSERT INTO `creature_template` (`entry`, `modelid1`, `modelid2`, `name`, `femaleName`, `subname`, `IconName`, `type`, `type_flags`, `VerifiedBuild`) VALUES ('119703', '1126', '75463', 'Scout through the Fargodeep Mine done.', ' ', '', '', '10', '1024', '23420');
DELETE FROM `creature_template_locale` WHERE entry = 119703;
INSERT INTO `creature_template_locale` (`entry`, `locale`, `Name`, `NameAlt`, `TitleAlt`) VALUES ('119703', 'ruRU', 'Разведка рудника Подземных глубин проведена.', NULL, NULL);
UPDATE `quest_template` SET Flags = 8 WHERE ID = 62;
UPDATE `quest_template_addon` SET SpecialFlags = 0 where ID = 62;
UPDATE `quest_objectives` SET Type = 0, ObjectID = 119703, Amount = 1, Flags = 1 WHERE QuestID = 62;
DELETE FROM `areatrigger_scripts` WHERE entry = 88;
INSERT INTO `areatrigger_scripts` VALUES (88, 'at_fargodeep_mine');
