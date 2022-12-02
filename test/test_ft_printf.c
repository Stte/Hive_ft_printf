#include "unity/unity.h"
#include "../libft.h"
#include <fcntl.h>
#include <unistd.h>
#include "../ft_printf.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_c_1_should_be_equal(void) {
	char	*expected;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;
	FILE *fp = freopen("outputs/test", "w+", stdout);

	expected = "This is a test";
	actual_len = ft_printf("Th%cs i%c a test", 'i', 's');
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("outputs/test", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(14, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_c_2_should_be_equal(void) {
	char	*expected;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;
	FILE *fp = freopen("outputs/test", "w+", stdout);

	expected = "is is";
	actual_len = ft_printf("%cs i%c", 'i', 's');
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("outputs/test", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(5, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_c_3_should_be_equal(void) {
	char	*expected;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;
	FILE *fp = freopen("outputs/test", "w+", stdout);

	expected = "This";
	actual_len = ft_printf("%c%c%c%c", 'T', 'h', 'i', 's');
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("outputs/test", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(4, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_s_1_should_be_equal(void) {
	char	*expected;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;
	FILE *fp = freopen("outputs/test", "w+", stdout);

	expected = "This";
	actual_len = ft_printf("%s", "This");
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("outputs/test", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(4, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_s_2_should_be_equal(void) {
	char	*expected;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;
	FILE *fp = freopen("outputs/test", "w+", stdout);

	expected = "This is a test";
	actual_len = ft_printf("This %s test", "is a");
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("outputs/test", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(14, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_s_3_should_be_equal(void) {
	char	*expected;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;
	FILE *fp = freopen("outputs/test", "w+", stdout);

	expected = "Thisis atest";
	actual_len = ft_printf("%s%s%s", "This", "is a", "test");
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("outputs/test", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(12, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_c_1_should_be_equal);
	RUN_TEST(test_c_2_should_be_equal);
	RUN_TEST(test_c_3_should_be_equal);
	RUN_TEST(test_s_1_should_be_equal);
	RUN_TEST(test_s_2_should_be_equal);
	RUN_TEST(test_s_3_should_be_equal);
	return UNITY_END();
}
