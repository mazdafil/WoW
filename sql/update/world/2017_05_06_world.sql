DELETE FROM `smart_scripts` WHERE entryorguid = 46383 AND event_type = 61;
DELETE FROM `smart_scripts` WHERE entryorguid = 46383 AND event_param2 = 30;
DELETE FROM `smart_scripts` WHERE entryorguid = 46383 AND event_param2 = 50;
UPDATE `creature_template` SET unit_flags = 512 WHERE entry IN (42492, 42515);
