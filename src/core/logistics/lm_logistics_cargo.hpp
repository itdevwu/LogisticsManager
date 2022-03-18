// Copyright 2022 Zhenglong WU(itdevwu)
#ifndef _LM_LOGISTICS_CARGO_HPP_
#define _LM_LOGISTICS_CARGO_HPP_

namespace lm
{
    enum CargoStatus
    {
        CARGO_STATUS_UNKNOWN = 0,
        CARGO_STATUS_WAITING,
        CARGO_STATUS_IN_TRANSIT,
        CARGO_STATUS_DELIVERING,
        CARGO_STATUS_DELIVERED,
        CARGO_STATUS_CANCELED,
        CARGO_STATUS_ERROR,
    };

    class Cargo
    {

    private:
        std::string _cargo_id;
        std::string _sender_id;
        std::string _receiver_id;
        std::string _fees;
        unsigned short _status;

    public:
    };
}

#endif // _LM_LOGISTICS_CARGO_HPP_