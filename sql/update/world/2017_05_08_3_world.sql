UPDATE `quest_objectives` SET Type = 0, ObjectID = 47971, Amount = 1, Description = 'Test the Gnomecorder at the Lakeshire Graveyard' WHERE ID = 266334;
INSERT INTO `quest_objectives_locale` VALUES (266334, 'ruRU', 26512, 0, 'Работа ГНМ-передатчика на кладбище Приозерья проверена', 19865);
UPDATE `quest_template` SET Flags = 589824, FlagsEx = 4 WHERE ID IN (26512, 26514, 26544);

