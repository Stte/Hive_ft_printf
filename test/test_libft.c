#include "unity/unity.h"
#include "../libft.h"

void setUp(void) {
}

void tearDown(void) {
}

//#region ft_atoi
void test_ft_atoi_should_be_equal_int(void) {
	TEST_ASSERT_EQUAL_INT(42, ft_atoi("42"));
}
//#endregion

//#region ft_isdigit
void test_ft_isdigit_should_be_true(void) {
	TEST_ASSERT_TRUE(ft_isdigit('1'));
}
void test_ft_isdigit_should_be_false(void) {
	TEST_ASSERT_FALSE(ft_isdigit('a'));
}
//#endregion
//#region ft_split
void test_tf_split_should_be_equal(void)
{
	char	*string = "  	Is th|is a| real 	...| nah";
	char	**expected = ((char*[5]){"  	Is th", "is a", " real 	...", " nah", NULL});
	char	**actual = ft_split(string, '|');
	TEST_ASSERT_EQUAL_STRING_ARRAY(expected, actual, 5);
	for (int i = 0; i < 5; i++)
		free(actual[i]);
	free(actual);
}
//#endregion


int main(void)
{
	UNITY_BEGIN();
	//#region ft_atoi
	RUN_TEST(test_ft_atoi_should_be_equal_int);
	//#endregion
	//#region ft_isdigit
	RUN_TEST(test_ft_isdigit_should_be_true);
	RUN_TEST(test_ft_isdigit_should_be_false);
	//#endregion
	//#region ft_split
	RUN_TEST(test_tf_split_should_be_equal);
	//#endregion
	return UNITY_END();
}
