int	is_word(char c)
{
	if ((c>= '0' && c <= '9') || (c >= 'a' && c <= 'z') 
					|| (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}
 
char	upper_change(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c);
	}
	else if ( c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}

char	lower_change(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	else if (c >= 'a' && c <= 'z')
	{
		return (c);
	}
	else
	{
		return (c);
	}
}

char	*ft_strcapitalize(char *str)
{
	int	idx;

	idx = 0;	
	while (str[idx])
	{
		if(is_word(str[idx]))
		{
			str[idx] = upper_change(str[idx]);
			idx++;
			break;	
		}
		idx++;
	}

	while (str[idx])
	{
		if (is_word(str[idx]) && !is_word(str[idx - 1]))
		{
			str[idx] = upper_change(str[idx]);
		}
		else if (is_word(str[idx]) && is_word(str[idx - 1]))
		{
			str[idx] = lower_change(str[idx]);
		}
		idx++;
	}
	return (str);
}

#include <stdio.h>
int main()
{
	char s[50] ="  i 234got  sf++s something to do";
	char *p;
	p = ft_strcapitalize(s);
	printf("%s", p);
}
