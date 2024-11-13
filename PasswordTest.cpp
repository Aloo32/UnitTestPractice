/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} 
		virtual ~PasswordTest(){} 
		virtual void SetUp(){} 
		virtual void TearDown(){}
};


TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, repeated_leading_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZZZabc");
	ASSERT_EQ(4, actual);
}

TEST(PasswordTest, no_repeated_leading_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Zabc");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, mixed_case_sensitive)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AAaaBB");
	ASSERT_EQ(2, actual);
}


TEST(PasswordTest, mixed_case_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Password123");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, all_uppercase_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("PASSWORD");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, alternating_mixed_case_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("PaSsWoRdYoU");
	ASSERT_TRUE(actual);
}

