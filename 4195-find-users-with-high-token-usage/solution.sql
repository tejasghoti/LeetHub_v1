# Write your MySQL query statement below
select user_id,count(tokens) as prompt_count,
round(avg(tokens),2) as avg_tokens
from prompts
group by user_id
having count(tokens) > 2 and max(tokens) > avg(tokens)
order by avg_tokens DESC, user_id ASC;
