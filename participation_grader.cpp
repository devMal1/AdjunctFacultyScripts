#include <iostream>

// P A R T I P A T I O N  G R A D E R
/*
This script calculates the GCU Online Class Participation grade (out of 20 points), based on
needing a minimum of 6 (substantive) posts over 3 days.
*/

using namespace std::string_literals;

const auto MIN_SUBSTANTIVE_POSTS = 6.0f;
const auto MIN_DAYS_POSTED = 3.0f;
constexpr auto FULL_POINTS = 20.0f;

struct Grade
{
    float points;
    float percentage;
};

Grade calculate_participation_grade(const unsigned int substantive_posts, const unsigned int days_posted)
{
    // Calculate substantive posts portion (out of 10)
    constexpr auto full_points_substantive_posts = FULL_POINTS / 2.0f;
    const auto substantive_posts_points = (substantive_posts / MIN_SUBSTANTIVE_POSTS) * full_points_substantive_posts;

    // Calculate days posted portion (out of 10)
    constexpr auto full_points_days_posted = FULL_POINTS / 2.0f;
    const auto days_posted_points = (days_posted / MIN_DAYS_POSTED) * full_points_days_posted;

    // Calculate total
    const auto total_points = substantive_posts_points + days_posted_points;
    const auto total_percent = total_points / FULL_POINTS;
    auto grade = Grade{.points = total_points, .percentage = total_percent};
    return grade;
}

int main()
{
    // Get substantive posts and days posted
    unsigned int substantive_posts;
    unsigned int days_posted;
    std::cout << "How many substantive posts?: "s;
    std::cin >> substantive_posts;
    std::cout << "How many days posted?: "s;
    std::cin >> days_posted;

    const auto participation_grade = calculate_participation_grade(substantive_posts, days_posted);

    std::cout << "Participation Grade: "s << participation_grade.points << " ("s << participation_grade.percentage << ")"s << std::endl;

    return 0;
}