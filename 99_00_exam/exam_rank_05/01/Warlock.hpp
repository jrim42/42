#ifndef WARLOCK_HPP
# define WARLOCK_HPP
// #pragma once

# include <iostream>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include <map>

class Warlock
{
    private:
        std::string name;
        std::string title;

        Warlock();
        Warlock(const Warlock &other);

        Warlock &operator=(const Warlock &other);

        std::map<std::string, ASpell *> arr;

    public:
        Warlock(const std::string &name, const std::string &title);
        ~Warlock();

        const std::string   &getName() const;
        const std::string   &getTitle() const;
        void                setTitle(const std::string &title);
        
        void    introduce() const;

        void    learnSpell(ASpell *aspell_ptr);
        void    forgetSpell(std::string name);
        void    launchSpell(std::string name, ATarget const &atarget_ref);
};

#endif