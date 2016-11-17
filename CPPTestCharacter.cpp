//! @file 
//! CPPTestCharacter class (used to test Character class defined in Character.h/Chracter.cpp)
//! Framework provided from Joey Paquet's COMP 345 website and adapted to include other methods implemented.
//! The librairies included are the necessary librairies for hte CPP Tests to be able to run. Also
//! included is the file 'Character.h' to be able to perofrm the checks on that class as well as 'Watcher.h'
//! to test teh observer pattern methods.

#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
using namespace CppUnit;
#include "Character.h"
#include "Watcher.h"

//! Test Class for the Character and Watcher classes.
class CharacterTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(CharacterTest);
	CPPUNIT_TEST(testValidNewCharacter);
	CPPUNIT_TEST(testInvalidNewCharacter);
	CPPUNIT_TEST(testGetHit);
	CPPUNIT_TEST(testRandomCharacter);
	CPPUNIT_TEST(testGetLevel);
	CPPUNIT_TEST(testAttached);
	CPPUNIT_TEST(testNotAttached);
	CPPUNIT_TEST_SUITE_END();
protected:
	void testValidNewCharacter();
	void testInvalidNewCharacter();
	void testGetHit();
	void testRandomCharacter();
	void testGetLevel();
	void testAttached();
	void testNotAttached();
};

//! Test case registration
CPPUNIT_TEST_SUITE_REGISTRATION(CharacterTest);

//! Test method to test the isValidCharacter() method of the Character class 
//! Test Case: a new level character should have all its ability scores in the [3-18] range
//! Tested item: Character::isValidCharacter()
void CharacterTest::testValidNewCharacter() {
	Character testBuddy = Character("Kronk", 3, 12, 12, 12, 12, 12, 12);
	CPPUNIT_ASSERT(testBuddy.isValidCharacter());
}

//! Test method to test the isValidCharacter() method of the Character class 
//! Test Case: a new level 3 character with scores outside the 3-18 range should return false
//! Tested item: Character::isValidCharacter()
void CharacterTest::testInvalidNewCharacter() {
	Character testBuddy = Character("Kronk", 3, 1, 12, 12, 12, 12, 12);
	CPPUNIT_ASSERT(testBuddy.isValidCharacter() == false);
}

//! Test method to test the getHit() and getHitPoints() methods of the Character class 
//! Test Case: character should have its hit points reduced by x, reduced by getHit, verified with getHitPoints 
//! Tested items: Character::getHit(), Character::getHitPoints(),
void CharacterTest::testGetHit() {
	Character testBuddy = Character("Kronk", 3, 10, 10, 10, 10, 10, 10);
	testBuddy.receiveAttack(1);
	CPPUNIT_ASSERT(testBuddy.getHitPoints() == 9);
}
//! Test method to test the isValidCharacter() method in conjunction with a randomly generated character.
//! Test Case: a level 3 character is generated with randomly generated scores
//! Tested items: Character::isValidCharacter, Character::Character(int)
void CharacterTest::testRandomCharacter() {
	Character testBuddy = Character(3);
	CPPUNIT_ASSERT(testBuddy.isValidCharacter());
}
//! Test method to test the getLevel() method of the Character class 
//! Test Case: a level 3 character created should report its level correctly 
//! Tested items: Character::getLevel()
void CharacterTest::testGetLevel() {
	Character testBuddy = Character("Kronk", 3, 10, 10, 10, 10, 10, 10);
	CPPUNIT_ASSERT(testBuddy.getLevel()==3);
}
//! Test method to test that a randomly generated Character is attached to a Watcher.
//! Test Case: a level 3 character is generated with randomly generated scores and attached to a Watcher.
//! Tested items: Watcher::findOutLevel(), Observer::Attach()
void CharacterTest::testAttached() {
	Character* testBuddy = new Character(3);
	Watcher* heroStalker = new Watcher(testBuddy);
	CPPUNIT_ASSERT(heroStalker->findOutLevel()==3);
}
//! Test method to test the characterIsDead method in conjunction with a randomly generated character.
//! Test Case: a level 3 character is generated with randomly generated scores and attached to a Watcher. It
//! receives a large amount of damage and the Watcher should observe that it is dead.
//! Tested item: Watcher::characterIsDead()
void CharacterTest::testNotAttached() {
	Character* testBuddy = new Character(3);
	Watcher* heroStalker = new Watcher(testBuddy);
	testBuddy->receiveAttack(99);
	CPPUNIT_ASSERT(heroStalker->characterIsDead()==0);
}