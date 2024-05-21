




namespace ilrd
{

    template <typename T>
    class Any
    {
        public:

        Any() = default;
        ~Any() = default;
        Any(const Any& other) = default;
        Any& operator=(const Any& other) = default;



        private:

        T m_value;
    };
}