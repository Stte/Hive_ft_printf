#include "unity/unity.h"
#include "../libft.h"
#include <fcntl.h>
#include <unistd.h>
#include "../ft_printf.h"

void setUp(void) {
}

void tearDown(void) {
	FILE *fp = freopen("test_output", "w+", stdout);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);
}

// c
void test_c_1_should_be_equal(void) {
	char	*expected;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;
	FILE *fp = freopen("test_output", "w+", stdout);

	expected = "This is a test";
	actual_len = ft_printf("Th%cs i%c a test", 'i', 's');
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
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
	FILE *fp = freopen("test_output", "w+", stdout);

	expected = "is is";
	actual_len = ft_printf("%cs i%c", 'i', 's');
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
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
	FILE *fp = freopen("test_output", "w+", stdout);

	expected = "This";
	actual_len = ft_printf("%c%c%c%c", 'T', 'h', 'i', 's');
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(4, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

// s
void test_s_1_should_be_equal(void) {
	char	*expected;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;
	FILE *fp = freopen("test_output", "w+", stdout);

	expected = "This";
	actual_len = ft_printf("%s", "This");
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
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
	FILE *fp = freopen("test_output", "w+", stdout);

	expected = "This is a test";
	actual_len = ft_printf("This %s test", "is a");
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
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
	FILE *fp = freopen("test_output", "w+", stdout);

	expected = "Thisis atest";
	actual_len = ft_printf("%s%s%s", "This", "is a", "test");
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(12, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

// p
void test_p_1_should_be_equal(void) {
	char	expected[101] = {0};
	int		expected_len;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;
	char	*str = "test";

	FILE *fp = freopen("test_output", "w+", stdout);

	expected_len = printf("hex: %p<--", str);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, expected, 100);
	close(fd);

	FILE *fp2 = freopen("test_output", "w+", stdout);

	actual_len = ft_printf("hex: %p<--", str);
	fclose(fp2);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_p_2_should_be_equal(void) {
	char	expected[101] = {0};
	int		expected_len;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;
	char	*str1 = "a";
	char	*str2 = "b";
	char	*str3 = "c";

	FILE *fp = freopen("test_output", "w+", stdout);

	expected_len = printf("%p%p%p", str1, str2, str3);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, expected, 100);
	close(fd);

	FILE *fp2 = freopen("test_output", "w+", stdout);

	actual_len = ft_printf("%p%p%p", str1, str2, str3);
	fclose(fp2);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_p_3_should_be_equal(void) {
	char	actual[101] = {0};
	int		actual_len;
	int		fd;

	FILE *fp = freopen("test_output", "w+", stdout);

	actual_len = ft_printf("%p", NULL);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(3, actual_len);
	TEST_ASSERT_EQUAL_STRING("0x0", actual);
}

// x
void test_x_1_should_be_equal(void) {
	char	expected[101] = {0};
	int		expected_len;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;

	FILE *fp = freopen("test_output", "w+", stdout);

	expected_len = printf("%x", 0);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, expected, 100);
	close(fd);

	FILE *fp2 = freopen("test_output", "w+", stdout);

	actual_len = ft_printf("%x", 0);
	fclose(fp2);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_x_2_should_be_equal(void) {
	char	expected[101] = {0};
	int		expected_len;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;

	FILE *fp = freopen("test_output", "w+", stdout);

	expected_len = printf("This is max hex: > %x <", -1);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, expected, 100);
	close(fd);

	FILE *fp2 = freopen("test_output", "w+", stdout);

	actual_len = ft_printf("This is max hex: > %x <", -1);
	fclose(fp2);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_x_3_should_be_equal(void) {
	char	expected[101] = {0};
	int		expected_len;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;

	FILE *fp = freopen("test_output", "w+", stdout);

	expected_len = printf("%x%x%x", -1, 0, 42);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, expected, 100);
	close(fd);

	FILE *fp2 = freopen("test_output", "w+", stdout);

	actual_len = ft_printf("%x%x%x", -1, 0, 42);
	fclose(fp2);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

// d
void test_d_1_should_be_equal(void) {
	char	expected[101] = {0};
	int		expected_len;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;

	FILE *fp = freopen("test_output", "w+", stdout);

	expected_len = printf("%d", -1);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, expected, 100);
	close(fd);

	FILE *fp2 = freopen("test_output", "w+", stdout);

	actual_len = ft_printf("%d", -1);
	fclose(fp2);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_d_2_should_be_equal(void) {
	char	expected[101] = {0};
	int		expected_len;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;

	FILE *fp = freopen("test_output", "w+", stdout);

	expected_len = printf("test%dtest", 0);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, expected, 100);
	close(fd);

	FILE *fp2 = freopen("test_output", "w+", stdout);

	actual_len = ft_printf("test%dtest", 0);
	fclose(fp2);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_d_3_should_be_equal(void) {
	char	expected[101] = {0};
	int		expected_len;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;

	FILE *fp = freopen("test_output", "w+", stdout);

	expected_len = printf("%d%d%d", -1, 0, 1000);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, expected, 100);
	close(fd);

	FILE *fp2 = freopen("test_output", "w+", stdout);

	actual_len = ft_printf("%d%d%d", -1, 0, 1000);
	fclose(fp2);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

// i
void test_i_1_should_be_equal(void) {
	char	expected[101] = {0};
	int		expected_len;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;

	FILE *fp = freopen("test_output", "w+", stdout);

	expected_len = printf("%i", -1);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, expected, 100);
	close(fd);

	FILE *fp2 = freopen("test_output", "w+", stdout);

	actual_len = ft_printf("%i", -1);
	fclose(fp2);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_i_2_should_be_equal(void) {
	char	expected[101] = {0};
	int		expected_len;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;

	FILE *fp = freopen("test_output", "w+", stdout);

	expected_len = printf("test%itest", 0);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, expected, 100);
	close(fd);

	FILE *fp2 = freopen("test_output", "w+", stdout);

	actual_len = ft_printf("test%itest", 0);
	fclose(fp2);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_i_3_should_be_equal(void) {
	char	expected[101] = {0};
	int		expected_len;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;

	FILE *fp = freopen("test_output", "w+", stdout);

	expected_len = printf("%i%i%i", -1, 0, 1000);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, expected, 100);
	close(fd);

	FILE *fp2 = freopen("test_output", "w+", stdout);

	actual_len = ft_printf("%i%i%i", -1, 0, 1000);
	fclose(fp2);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

// X
void test_upper_x_1_should_be_equal(void) {
	char	expected[101] = {0};
	int		expected_len;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;

	FILE *fp = freopen("test_output", "w+", stdout);

	expected_len = printf("%X", 0);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, expected, 100);
	close(fd);

	FILE *fp2 = freopen("test_output", "w+", stdout);

	actual_len = ft_printf("%X", 0);
	fclose(fp2);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_upper_x_2_should_be_equal(void) {
	char	expected[101] = {0};
	int		expected_len;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;

	FILE *fp = freopen("test_output", "w+", stdout);

	expected_len = printf("This is max hex: > %X <", -1);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, expected, 100);
	close(fd);

	FILE *fp2 = freopen("test_output", "w+", stdout);

	actual_len = ft_printf("This is max hex: > %X <", -1);
	fclose(fp2);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
}

void test_upper_x_3_should_be_equal(void) {
	char	expected[101] = {0};
	int		expected_len;
	char	actual[101] = {0};
	int		actual_len;
	int		fd;

	FILE *fp = freopen("test_output", "w+", stdout);

	expected_len = printf("%X%X%X", -1, 0, 42);
	fclose(fp);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, expected, 100);
	close(fd);

	FILE *fp2 = freopen("test_output", "w+", stdout);

	actual_len = ft_printf("%X%X%X", -1, 0, 42);
	fclose(fp2);
	freopen("/dev/tty", "w", stdout);

	fd = open("test_output", O_RDWR);
	read(fd, actual, 100);
	close(fd);

	TEST_ASSERT_EQUAL_INT(expected_len, actual_len);
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
	RUN_TEST(test_p_1_should_be_equal);
	RUN_TEST(test_p_2_should_be_equal);
	RUN_TEST(test_p_3_should_be_equal);
	RUN_TEST(test_x_1_should_be_equal);
	RUN_TEST(test_x_2_should_be_equal);
	RUN_TEST(test_x_3_should_be_equal);
	RUN_TEST(test_d_1_should_be_equal);
	RUN_TEST(test_d_2_should_be_equal);
	RUN_TEST(test_d_3_should_be_equal);
	RUN_TEST(test_i_1_should_be_equal);
	RUN_TEST(test_i_2_should_be_equal);
	RUN_TEST(test_i_3_should_be_equal);
	RUN_TEST(test_upper_x_1_should_be_equal);
	RUN_TEST(test_upper_x_2_should_be_equal);
	RUN_TEST(test_upper_x_3_should_be_equal);
	return UNITY_END();
}
